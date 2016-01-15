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
    int time = 0;

    QGraphicsEllipseItem *posHelper;//Pour le aider à debugger

    int nbEmissions; // Nombre d'émissions à disposition
    int nbCheckpoints; // Nombre de checkpoints du niveau



private:
    TiledJsonMapParsor *mapParsor;
    QGraphicsPixmapItem *sonarView;

    void checkIfPlayersTogheter();

    void decreaseValue(int value);

public slots:
    void timer();

};

#endif // GAMESCENE_H
