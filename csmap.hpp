#ifndef CSMAP_H
#define CSMAP_H

#include <QString>

class CSMap
{
public:
    CSMap();
    CSMap(QString bspPath = QString(), QString bspName = QString(), QString thumbPath = QString());

    void setBSPath(QString path);
    void setBSPName(QString name);
    void setThumbPath(QString path);

    QString getBSPath();
    QString getBSPName();
    QString getThumbPath();
private:
    QString m_bspPath, m_bspName, m_thumbPath; // Chemins du fichier et du thumbnail
};

#endif // CSMAP_H
