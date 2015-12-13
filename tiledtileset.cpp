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
