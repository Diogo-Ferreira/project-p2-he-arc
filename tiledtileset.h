#ifndef TILEDTILESET_H
#define TILEDTILESET_H

#include <QtWidgets>
class TiledTileSet
{
public:
    TiledTileSet(int firstGid,QString fileName,int tileW,int tileH);
    TiledTileSet(QJsonObject);
    QPixmap getTile(int index);
    int tileWidth;
    int tileHeight;
private:
    QPixmap *tileSheetImage;
    int firstgid;
signals:

public slots:
};

#endif // TILEDTILESET_H
