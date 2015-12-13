#include "tiledlayergroupitem.h"

TiledLayerGroupItem::TiledLayerGroupItem(QJsonObject data,TiledTileSet* tileset):QGraphicsItemGroup()
{
    this->data = data["data"].toArray();
    this->name = data["name"].toString();
    this->visible = data["visible"].toBool();
    this->width = data["width"].toInt();
    this->height = data["height"].toInt();
    this->tileset = tileset;
    buildLayer();
}


void TiledLayerGroupItem::buildLayer()
{
    int c =0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int index = c++;
            qDebug() << data.at(index).toInt()-1;
            QPixmap p = tileset->getTile(data.at(index).toInt()-1);
            QGraphicsPixmapItem *pix = new QGraphicsPixmapItem(p);
            pix->setPos(j * (32),i * (32));
            //pix->setPos(0,0);
            addToGroup(pix);
        }
    }
}
