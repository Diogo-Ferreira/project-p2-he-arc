#ifndef TILEDLAYERGROUPITEM_H
#define TILEDLAYERGROUPITEM_H
#include <QtWidgets>
#include "tiledtileset.h"
#include <QGraphicsView>
class TiledLayerGroupItem : public QGraphicsItemGroup
{
public:
    TiledLayerGroupItem(QJsonObject data,TiledTileSet* tileset);
    QJsonArray data;
    QString name;
    bool visible;
    int width;
    int height;

private:
    TiledTileSet *tileset;
    void buildLayer();

signals:

public slots:
};

#endif // TILEDLAYERGROUPITEM_H
