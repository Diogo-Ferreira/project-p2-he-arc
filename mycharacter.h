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
    MyCharacter(int x, int y,bool isSelected,QGraphicsScene *parent,TiledJsonMapParsor *mapParsor);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    void setImage(bool isSelectedPlayer);
    void stop();
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyRight = false;
    bool KeyLeft = false;
    bool personnage = true;
    int id;
    QTimer *hitAnimationTimer;
    QTimer *updateTimer;
    int pixSize;//pour y accéder rapidement


private :
    SonarPowar *sonarPower;
    TiledJsonMapParsor *mapParsor;
    void sonar();
    int speed = 1;
    bool isSelectedPlayer;
public slots :
    void updateEnv();
    void touched();
    void animationTouched();
};

#endif // MYCHARACTER

