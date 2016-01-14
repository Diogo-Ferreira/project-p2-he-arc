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
    bool doesPlayerCollide(QPoint pos,QRect bounds);
private:
    //Accesseur et getters encore à définir
    int mapWidthInTiles;
    int mapHeightInTiles;
    int tileWidth;
    int tileHeight;
    QList<TiledTileSet*> *tilesets;//int -> firstgid
    void preloadData(QJsonDocument doc);
};

#endif // TILEDJSONMAPPARSOR_H
