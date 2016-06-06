#include "config.hpp"
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

Config::Config(QMainWindow *widget)
{

    QFile file(this->configPath);

    if(file.open(QIODevice::ReadWrite)) { // Ouverture en lecture et écriture du fichier config.txt
        QTextStream textFile(&file); // Flux spécialisé en texte
        QString path = textFile.readLine(); // Lecture du contenu

        /* Si le contenu est valide */
        if(this->checkPath(path)) {
            this->CSPath = path;
            textFile.flush();
            file.close();
        }

        /* S'il n'est pas valide */
        else {
            QString truePath;

            /* Demande le bon dossier a l'utilisateur jusqu'à ce que ce soit le bon */
            do {
                truePath = this->askFolder(widget);
            } while (!this->checkPath(truePath));

            textFile << truePath; // Ecriture du chemin dans le fichier
            textFile.flush();
            file.close();
        }
    }
}

/* Fonction demandant l'emplacement du dossier a l'aide d'un dialogue */
QString Config::askFolder(QMainWindow *widget) {
    return QFileDialog::getExistingDirectory(widget, widget->tr("Veuillez sélectionner le dossier \"Counter-Strike Global Offensive\""), QDir::homePath(), QFileDialog::ShowDirsOnly);
}

/* Fonction vérifiant si un dossier quelquonque correspond bel et bien au dossier CSGO, et ce en vérifant l'existence de celui-ci et des sous-dossiers csgo, maps, et workshop */
bool Config::checkPath(QString path) {

    /* Si le String n'est pas vide */
    if(!path.isEmpty()) {
        QFileInfo fileInfo(path);

        /* Si le dossier existe bel est bel, et que c'est bien un dossier et non un fichier */
        if(fileInfo.exists() && fileInfo.isDir()) {
            QString mapsPath = path + "/csgo/maps/workshop"; // Test du chemin contenant les maps de la communauté
            QFileInfo workshopInfo(mapsPath);

            /* Si le dossier workshop est lui aussi valide */
            if(workshopInfo.exists() && workshopInfo.isDir()) {
                return true;
            } else
                return false;

        } else
            return false;

    } else
        return false;
}

/* Fonction retournant le chemin du dossier Counter-Strike */
QString Config::getCSPath() {
    return this->CSPath;
}
