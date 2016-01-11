#ifndef MYCHARACTER
#define MYCHARACTER

//#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>
#include "sonarpowar.h"
class TiledJsonMapParsor;
class MyCharacter: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public :
    MyCharacter(int x, int y,QGraphicsScene *parent,TiledJsonMapParsor *mapParsor);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyRight = false;
    bool KeyLeft = false;
    bool personnage = true;
    QPixmap *pix;
    int id;
    QTimer *hitAnimationTimer;
    QTimer *updateTimer;

private :
    SonarPowar *sonarPower;
    TiledJsonMapParsor *mapParsor;
    void sonar();
    int speed = 1;
public slots :
    void updateEnv();
    void touched();
    void animationTouched();
};

#endif // MYCHARACTER

