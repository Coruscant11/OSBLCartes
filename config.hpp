#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QMainWindow>

class Config
{
public:
    Config(QMainWindow *widet);
    bool checkPath(QString path);
    QString getCSPath();
private:
    QString askFolder(QMainWindow *window);
    QString CSPath; // Chemin du dossier CSGO
    const QString configPath = "config.txt"; // Chemin du dossier contenant l'emplacement du dossier CSGO
};

#endif // CONFIG_H
