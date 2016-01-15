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
    bool isFired;

private:
    QGraphicsPixmapItem *sonarView;
    QGraphicsPixmapItem * circle;
    QGraphicsScene *scene;
    MyCharacter *player;
    TiledJsonMapParsor *mapParsor;
    bool isAnimFinished;
    double animIter;

    double animSpeed = 0.01/3;//A regler en fonction de l'update
    int pixSize;//pour y accéder plus rapidement


};

#endif // SONARPOWAR_H
