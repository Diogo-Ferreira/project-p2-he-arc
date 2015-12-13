#ifndef TILEDJSONMAPPARSOR_H
#define TILEDJSONMAPPARSOR_H

#include <QtWidgets>
#include "tiledtileset.h"
#include "tiledlayergroupitem.h"
class TiledJsonMapParsor
{
public:
    TiledJsonMapParsor(QString mapName);
    QHash< QString, TiledLayerGroupItem *> *layers;
private:
    int mapWidthInTiles;
    int mapHeightInTiles;
    int tileWidth;
    int tileHeight;
    QList<TiledTileSet*> *tilesets;//int -> firstgid
    void preloadData(QJsonDocument doc);
    void drawMap();
signals:

public slots:
};

#endif // TILEDJSONMAPPARSOR_H
