#include "tiledtileset.h"
/**
 * @brief Ensemble de tuilles pour la map
 * @param firstGid premier id (réf dans le fichier json)
 * @param fileName chemin fichier du tileset
 * @param tileW largeur d'une tuille
 * @param tileH hauteur d'une tuille
 */
TiledTileSet::TiledTileSet(int firstGid,QString fileName,int tileW,int tileH)
{

   this->firstgid = firstGid;
   tileSheetImage = new QPixmap(fileName);
   this->tileHeight = tileH;
   this->tileWidth = tileW;
}
/**
 * @brief Ensemble de tuilles pour la map
 * @param data données du tileset format JSON
 */
TiledTileSet::TiledTileSet(QJsonObject data)
{
    firstgid = data["firstgid"].toInt();
    tileSheetImage = new QPixmap( QString("%1/%2").arg(":/map", data["image"].toString()) );
    tileHeight = data["tileheight"].toInt();
    tileWidth = data["tilewidth"].toInt();
    fillProperties(data);
}
/**
 * @brief Remplit la liste de propirétées
 * @param data données format JSON
 */
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
/**
 * @brief Récupère la tuille suivant son ID, attention il y a une différence de 1
 *        entre les index du fichier et ceux afficher dans l'interface de tiled.
 * @param index identifiant de la tuille, voir sous tiled et faire -1
 * @return image de la tuille
 */
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
/**
 * @brief Récupère les propriétées d'une tuille par son ID
 * @param index ID tuille
 * @return hash des propriétées
 */
QHash<QString, QString> TiledTileSet::getTileProps(int index)
{
    return propreties->value(QString::number(index));
}
