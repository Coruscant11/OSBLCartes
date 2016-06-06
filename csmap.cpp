#include "csmap.hpp"

CSMap::CSMap(QString bspPath, QString bspName, QString thumbPath) : m_bspPath(bspPath), m_bspName(bspName), m_thumbPath(thumbPath) {}

void CSMap::setBSPath(QString path) {
    this->m_bspPath = path;
}

void CSMap::setBSPName(QString name) {
    this->m_bspName = name;
}

void CSMap::setThumbPath(QString path) {
    this->m_thumbPath = path;
}

QString CSMap::getBSPath() {
    return this->m_bspPath;
}

QString CSMap::getBSPName() {
    return this->m_bspName;
}

QString CSMap::getThumbPath() {
    return this->m_thumbPath;
}
