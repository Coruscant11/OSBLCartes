#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onCurrentItemChange(QListWidgetItem*, QListWidgetItem*);
    void openCSGODir();
    void openItemDir();
    void upload();
private:
    Ui::MainWindow *ui; // Permet l'accès aux widgets
    void checkConfig();
    void connectWidgets();
    void loadQListWidget();
    QString CSPath; // Chemin du dossier CSGO
};

#endif // MAINWINDOW_HPP
