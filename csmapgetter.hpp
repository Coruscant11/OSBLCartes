#ifndef CSMAPGETTER_H
#define CSMAPGETTER_H

#include <QString>
#include <vector>
#include "csmap.hpp"

class CSMapGetter
{
public:
    CSMapGetter(QString CSPath);
    std::vector<CSMap>  getMaps();
private:
    QString m_CSPath; // Chemin du dossier CSGO
    QString m_WorkshopDirectoryPath; // Chemin du dossier workshop de CSGO
    QStringList getMapsFolders();
    QString getBestPic(QString folder);
    QString getBSPFile(QString folder);
};

#endif // CSMAPGETTER_H
