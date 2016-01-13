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
<<<<<<< HEAD
=======
    QGraphicsEllipseItem *posHelper;//Pour le aider à debugger

    int nbEmissions; // Nombre d'émissions à disposition
    int nbCheckpoints; // Nombre de checkpoints du niveau

>>>>>>> ed36e6164593e72686d8faff2f1d359660a2d0f2
protected:

private:
    TiledJsonMapParsor *mapParsor;
    QGraphicsPixmapItem *sonarView;
<<<<<<< HEAD
    void checkIfPlayersTogheter();
=======

    void decreaseValue(int value);
>>>>>>> ed36e6164593e72686d8faff2f1d359660a2d0f2
};

#endif // GAMESCENE_H
