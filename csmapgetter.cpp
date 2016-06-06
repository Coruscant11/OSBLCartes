#include "csmapgetter.hpp"

#include <vector>
#include <QDirIterator>
#include <QFile>
#include <QBitmap>
#include <QDebug>

/* Constructeur définissant les variables de classes contenant l'accès au dossier CSGO et a celui du workshop CSGO */
CSMapGetter::CSMapGetter(QString CSPath) : m_CSPath(CSPath) {
    this->m_WorkshopDirectoryPath = this->m_CSPath + "/csgo/maps/workshop/";
}

/* Fonction retournant un vecteur d'objets CSMap contenant toutes les informations nécessaires sur chaque maps de la communauté téléchargée */
std::vector<CSMap> CSMapGetter::getMaps() {

    std::vector<CSMap> maps; // Le vecteur

    QStringList foldersMaps = this->getMapsFolders(); // Liste de chemin contenant tous les dossiers de chaque map

    /* On prend chaque map dans chaque dossier */
    foreach (QString dirPath, foldersMaps) {
        QString bspPath, bspName, picPath;

        bspPath = this->getBSPFile(dirPath);
        picPath = this->getBestPic(dirPath);

        QFileInfo fileInfo(bspPath);
        bspName = fileInfo.baseName();

        CSMap csmap(bspPath, bspName, picPath);
        maps.push_back(csmap);
    }

    return maps;
}

/* Fonction retournant la liste de chaque dossier de chaque maps */
QStringList CSMapGetter::getMapsFolders() {
    QString workshopDirectoryPath = this->m_CSPath + "/csgo/maps/workshop/"; // Chemin du dossier workshop
    QStringList all_dirs; // Liste contenant chaque dossier

        /* On ajoute chaque sous-dossier a la liste */
        QDirIterator directories(workshopDirectoryPath, QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);
        while(directories.hasNext()){
            directories.next();
            all_dirs.push_back(directories.filePath() + "/");
        }

    return all_dirs;
}

/* Fonction retournant le chemin du thumbnail en taille normale */
QString CSMapGetter::getBestPic(QString dirPath) {
    QDir dir(dirPath);
    QStringList filters;
    filters << "*.jpg";

    QStringList jpgList = dir.entryList(filters, QDir::Files);

    return dirPath + jpgList[0];
}

/* Fonction retournant le chemin du fichier .bsp */
QString CSMapGetter::getBSPFile(QString dirPath) {
    QDir dir(dirPath);
    QStringList filters;
    filters << "*.bsp";

    QString finalBsp;
    QStringList bspList = dir.entryList(filters, QDir::Files);

    foreach(QString bsp, bspList)
        finalBsp = bsp;

    return dirPath + finalBsp;
}
