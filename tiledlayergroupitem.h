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
    QHash<QString,QString> getTilePropretyByPos(int x,int y);
    QPixmap getLayerImgCopy(int x,int y,int w,int h,QPixmap mask);
private:
    QPixmap *layerImg;
    TiledTileSet *tileset;
    void buildLayer();
    void createLayerImg();

signals:

public slots:
};

#endif // TILEDLAYERGROUPITEM_H
