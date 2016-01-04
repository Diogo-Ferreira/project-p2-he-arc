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
    int xPosInTiles = (int)(x / width);
    int yPosInTIles = (int)(y / height)+1;
    int index = yPosInTIles * width + xPosInTiles;
    qDebug() << xPosInTiles << " " << yPosInTIles;
    return tileset->getTileProps(data.at(index).toInt()-1);
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
    if(mask.isNull())
        return this->layerImg->copy(x,y,w,h);
    else{
        QPixmap imgRectCopy = this->layerImg->copy(x,y,w,h);
        imgRectCopy.setMask(mask.scaled(w,h).mask());
        return imgRectCopy;
    }
}
