#include "mainwindow.hpp"
#include "config.hpp"
#include "csmapgetter.hpp"
#include "csmap.hpp"
#include "uploader.hpp"

#include <QMessageBox>
#include <QPixmap>
#include <vector>
#include <QFileInfo>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 550); // Bloque la taille de la fenêtre (on ne peut plus la redimensionner)
    this->checkConfig();
    this->connectWidgets();
    this->loadQListWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Fonction vérifiant si le fichier texte contenant le chemin du dossier CS:Go est valide */
void MainWindow::checkConfig() {
    Config c(this);
    this->CSPath = c.getCSPath();
}

/* Fonction du connexion des SIGNALs de nos widgets à leurs SLOTs */
void MainWindow::connectWidgets() {
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(ui->listWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentItemChange(QListWidgetItem*, QListWidgetItem*)));
    QObject::connect(ui->openCsButton, SIGNAL(clicked()), this, SLOT(openCSGODir()));
    QObject::connect(ui->openItemButton, SIGNAL(clicked()), this, SLOT(openItemDir()));
    QObject::connect(ui->uploadButton, SIGNAL(clicked()), this, SLOT(upload()));
}

void MainWindow::loadQListWidget() {
    CSMapGetter getter(this->CSPath);
    std::vector<CSMap> maps = getter.getMaps();
    foreach(CSMap map, maps) {
        QListWidgetItem *item = new QListWidgetItem(map.getBSPName());
        item->setText(map.getBSPName());
        item->setData(52775, map.getBSPath());
        item->setData(52776, map.getThumbPath());
        item->setData(52777, map.getBSPName());
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
    }
}

void MainWindow::onCurrentItemChange(QListWidgetItem *current, QListWidgetItem *previous) {
    QPixmap *pixmap = new QPixmap(current->data(52776).toString());
    ui->img->setPixmap(*pixmap);
    ui->img->setScaledContents(true);

    ui->mapNameLabel->setText(current->data(52777).toString());
    QFileInfo fileInfo(current->data(52775).toString());
    ui->mapSizeLabel->setText(QString::number(fileInfo.size() / 1000000) + " Mo");
}

void MainWindow::openCSGODir() {
    QDesktopServices::openUrl(QUrl::fromLocalFile(this->CSPath));
}

void MainWindow::openItemDir() {
    QFileInfo fileInfo(ui->listWidget->currentItem()->data(52775).toString());
    QString path = fileInfo.absoluteDir().absolutePath();
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MainWindow::upload() {
    QStringList filesToUpload;

    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        if(item->checkState() == Qt::Checked)
            filesToUpload.push_back(item->data(52775).toString());
    }

}
