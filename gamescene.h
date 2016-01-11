#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include "mycharacter.h"
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include <QObject>
#include "tiledjsonmapparsor.h"
#include "gamehud.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    GameScene();
    QList<MyCharacter*> characters;
    int character = 0;
    GameHUD *gameHUD;
    QGraphicsEllipseItem *posHelper;//Pour le aider à debugger

    int nbEmissions; // Nombre d'émissions à disposition
    int nbCheckpoints; // Nombre de checkpoints du niveau

protected:

private:
    TiledJsonMapParsor *mapParsor;
    QGraphicsPixmapItem *sonarView;

    void decreaseValue(int value);
};

#endif // GAMESCENE_H
