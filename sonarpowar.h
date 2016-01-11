#ifndef SONARPOWAR_H
#define SONARPOWAR_H
#include <QtWidgets>
//#include "mycharacter.h"
class MyCharacter;
class TiledJsonMapParsor;

class SonarPowar
{
public:
    SonarPowar(QGraphicsScene *scene,MyCharacter *player,TiledJsonMapParsor *mapParsor);
    void fire();
    void update();

private:
    QGraphicsPixmapItem *sonarView;
    QGraphicsPixmapItem * circle;
    QGraphicsScene *scene;
    MyCharacter *player;
    TiledJsonMapParsor *mapParsor;
    bool isAnimFinished;
    double animIter;
    bool isFired;
    double animSpeed = 0.01/2;//A regler en fonction de l'update


};

#endif // SONARPOWAR_H
