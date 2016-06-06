/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QFrame *frame;
    QLabel *img;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *mapNameLabel;
    QLabel *mapSizeLabel;
    QListWidget *listWidget;
    QLabel *label_2;
    QPushButton *uploadButton;
    QPushButton *openCsButton;
    QPushButton *openItemButton;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 567);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/JPCar/Pictures/csgo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(48, 48));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(500, 10, 361, 331));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 40, 301, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        img = new QLabel(frame);
        img->setObjectName(QStringLiteral("img"));
        img->setGeometry(QRect(14, 15, 271, 141));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 250, 111, 31));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 280, 111, 31));
        label_4->setFont(font);
        mapNameLabel = new QLabel(groupBox);
        mapNameLabel->setObjectName(QStringLiteral("mapNameLabel"));
        mapNameLabel->setGeometry(QRect(150, 250, 201, 31));
        mapSizeLabel = new QLabel(groupBox);
        mapSizeLabel->setObjectName(QStringLiteral("mapSizeLabel"));
        mapSizeLabel->setGeometry(QRect(150, 280, 141, 31));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 431, 431));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(24, 20, 391, 21));
        uploadButton = new QPushButton(centralWidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(500, 430, 361, 51));
        uploadButton->setIconSize(QSize(40, 40));
        openCsButton = new QPushButton(centralWidget);
        openCsButton->setObjectName(QStringLiteral("openCsButton"));
        openCsButton->setGeometry(QRect(500, 360, 171, 51));
        openItemButton = new QPushButton(centralWidget);
        openItemButton->setObjectName(QStringLiteral("openItemButton"));
        openItemButton->setGeometry(QRect(680, 360, 181, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 26));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Informations sur la map s\303\251lectionn\303\251e", 0));
        img->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Nom de la map :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Taille de la map :", 0));
        mapNameLabel->setText(QString());
        mapSizeLabel->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Veuillez s\303\251lectionner les maps que vous voulez envoyer.", 0));
        uploadButton->setText(QApplication::translate("MainWindow", "Uploader les images", 0));
        openCsButton->setText(QApplication::translate("MainWindow", "Ouvrir le dossier CSGO", 0));
        openItemButton->setText(QApplication::translate("MainWindow", "Ouvrir le dossier de la map", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
