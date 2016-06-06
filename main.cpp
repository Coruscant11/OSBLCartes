#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    /* Lancement du programme */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec(); // Execution
}
