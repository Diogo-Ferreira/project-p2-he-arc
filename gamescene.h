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
    //QList<MyRect*> characters;
    QList<MyCharacter*> characters;
    int character = 0;
    QGraphicsPixmapItem * circle;
    QTimer * timer;
    bool isSonar;
    bool animationfinie;
    GameHUD *gameHUD;
    double i;
    QGraphicsEllipseItem *posHelper;//Pour le aider à debugger
protected:

private:
    TiledJsonMapParsor *mapParsor;
    QGraphicsPixmapItem *sonarView;

public slots:
    void removeCircle();
     void updateCircle();
};

#endif // GAMESCENE_H
