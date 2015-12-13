#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>
#include "myrect.h"
#include "mycharacter.h"
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include <QObject>
#include "tiledjsonmapparsor.h"

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
    QGraphicsEllipseItem * circle;
    QTimer * timer;
    bool isSonar;
protected:

private:
    TiledJsonMapParsor *mapParsor;

public slots:
    void removeCircle();
};

#endif // GAMESCENE_H
