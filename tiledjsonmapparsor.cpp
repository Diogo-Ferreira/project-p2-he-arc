#include "tiledjsonmapparsor.h"
#include "tiledtileset.h"
TiledJsonMapParsor::TiledJsonMapParsor(QString mapName)
{

    QString val;
    QFile file;
    tilesets = new QList<TiledTileSet*>();
    layers = new QHash<QString,TiledLayerGroupItem*>();
    file.setFileName(mapName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    preloadData(d);

}


void TiledJsonMapParsor::preloadData(QJsonDocument doc)
{
    QJsonObject mainProps = doc.object();
    tileHeight = mainProps["tileheight"].toInt();
    tileHeight = mainProps["tilewidth"].toInt();
    mapHeightInTiles = mainProps["height"].toInt();
    mapWidthInTiles = mainProps["width"].toInt();

    //TileSets...
    QJsonArray tilesetsArr = mainProps["tilesets"].toArray();
    for(int i=0;i< tilesetsArr.count(); i++)
    {
        QJsonObject temp = tilesetsArr.at(i).toObject();
        tilesets->append(new TiledTileSet(temp));
    }

    //Layers
    QJsonArray layersArr = mainProps["layers"].toArray();
    for(int i=0;i< layersArr.count(); i++)
    {
        QJsonObject temp = layersArr.at(i).toObject();
        layers->insert(QString(temp["name"].toString()),new TiledLayerGroupItem(temp,tilesets->first()));
    }
}

bool TiledJsonMapParsor::doesPlayerCollide(QPoint pos, QRect bounds)
{
    QHash<QString,QString> prop = layers->value("Ground")->getTilePropretyByPos(pos.x(),pos.y());

    if(prop.contains("block")) return true;
    else return false;
}
