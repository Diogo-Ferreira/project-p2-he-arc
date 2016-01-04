#include "tiledtileset.h"

TiledTileSet::TiledTileSet(int firstGid,QString fileName,int tileW,int tileH)
{

   this->firstgid = firstGid;
   tileSheetImage = new QPixmap(fileName);
   this->tileHeight = tileH;
   this->tileWidth = tileW;
}

TiledTileSet::TiledTileSet(QJsonObject data)
{
    firstgid = data["firstgid"].toInt();
    tileSheetImage = new QPixmap(data["image"].toString());
    tileHeight = data["tileheight"].toInt();
    tileWidth = data["tilewidth"].toInt();
    fillProperties(data);
}


void TiledTileSet::fillProperties(QJsonObject data)
{
    propreties = new QHash<QString,QHash<QString,QString> >();
    QJsonObject tileProps = data["tileproperties"].toObject();
    foreach(QString v,tileProps.keys())
    {
        QJsonObject o = tileProps[v].toObject();
        QHash<QString,QString> propsHash = QHash<QString,QString>();
        foreach(QString propKeys,o.keys()){
            propsHash.insert(propKeys,o[propKeys].toString());
        }
        propreties->insert(v,propsHash);
    }
}


QPixmap TiledTileSet::getTile(int index)
{
    QRect tile = QRect(
                1 + (index % 8) * (tileWidth+1),
                1 + (int)(index / 8) * (tileHeight+1),
                tileWidth,
                tileHeight
    );
    return tileSheetImage->copy(tile);
}

QHash<QString, QString> TiledTileSet::getTileProps(int index)
{
    return propreties->value(QString::number(index));
}
