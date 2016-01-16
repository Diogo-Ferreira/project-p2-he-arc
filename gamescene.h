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
    //Dans notre cas avec 2 joueurs la liste n'est pas très adapter, mais au moins on peut ajouter plusieurs personnages sans limites par la suite
    QList<MyCharacter*> characters;
    int characterId = 0;
    GameHUD *gameHUD;
    int time = 0;
    QGraphicsEllipseItem *posHelper;//Pour le aider à debugger

private:
    TiledJsonMapParsor *mapParsor;
    QGraphicsPixmapItem *sonarView;
    void checkIfPlayersArentDead();
    void checkIfPlayersTogheter();
public slots:
    void timer();

};

#endif // GAMESCENE_H
