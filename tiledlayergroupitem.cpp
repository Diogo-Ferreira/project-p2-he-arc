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
    createLayerImg();
}

QHash<QString, QString> TiledLayerGroupItem::getTilePropretyByPos(int x, int y)
{
    x += 320;
    y += 640;
    int xPosInTiles = (int)(x / 32);
    int yPosInTIles = (int)(y / 32);
    int index = yPosInTIles*60 + (xPosInTiles+1);
    qDebug() << xPosInTiles << " " << yPosInTIles << " " << data.at(index-1).toInt()-1;
    return tileset->getTileProps(data.at(index-1).toInt()-1);
}


void TiledLayerGroupItem::buildLayer()
{
    int c =0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int index = c++;
            //qDebug() << data.at(index).toInt()-1;
            QPixmap p = tileset->getTile(data.at(index).toInt()-1);
            QGraphicsPixmapItem *pix = new QGraphicsPixmapItem(p);
            pix->setPos(j * (tileset->tileWidth),i * (tileset->tileHeight));
            //pix->setPos(0,0);
            addToGroup(pix);
        }
    }
}

void TiledLayerGroupItem::createLayerImg(){
    QGraphicsScene *tempScene = new QGraphicsScene();
    tempScene->addItem(this);
    layerImg = new QPixmap(width * tileset->tileWidth,height * tileset->tileHeight);
    QPainter *p = new QPainter(layerImg);
    tempScene->render(p);
}

QPixmap TiledLayerGroupItem::getLayerImgCopy(int x,int y,int w,int h,QPixmap mask){
    //Quick Fix, dirty as fuck
    x += 320;
    y += 640;
    if(mask.isNull())
        return this->layerImg->copy(x,y,w,h);
    else{
        QPixmap imgRectCopy = this->layerImg->copy(x,y,w,h);
        imgRectCopy.setMask(mask.scaled(w,h).mask());
        return imgRectCopy;
    }
}
