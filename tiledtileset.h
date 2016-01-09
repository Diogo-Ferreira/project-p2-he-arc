#ifndef TILEDTILESET_H
#define TILEDTILESET_H

#include <QtWidgets>
class TiledTileSet
{
public:
    TiledTileSet(int firstGid,QString fileName,int tileW,int tileH);
    TiledTileSet(QJsonObject);
    QPixmap getTile(int index);
    QHash<QString,QString> getTileProps(int index);
    int tileWidth;
    int tileHeight;
    QHash<QString,QHash<QString,QString> > *propreties;//<TileId,<PropName,PropValue>>
private:
    QPixmap *tileSheetImage;
    void fillProperties(QJsonObject data);
    int firstgid;
signals:

public slots:
};

#endif // TILEDTILESET_H
