#include "mycharacter.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include "tiledjsonmapparsor.h"

MyCharacter::MyCharacter(int x, int y,QGraphicsScene* parent,TiledJsonMapParsor *mapParsor)
{

    this->mapParsor = mapParsor;
    this->setX(x);
    this->setY(y);
    pix = new QPixmap(":/img/character/blueballhalo.png");
    setPixmap(pix->copy(0,0,50,50));
    updateTimer = new QTimer();
    QObject::connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateEnv()));
    sonarPower = new SonarPowar(parent,this,mapParsor);
    updateTimer->start(3);
}

void MyCharacter::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_A :
        case Qt::Key_Left :
            this->KeyLeft = true;
            setPixmap(pix->copy(0,575,50,75));
            break;
        case Qt::Key_D :
        case Qt::Key_Right :
            this->KeyRight = true;
            setPixmap(pix->copy(0,705,50,75));
            break;
        case Qt::Key_W :
        case Qt::Key_Up :
            this->KeyUp = true;
            setPixmap(pix->copy(0,510,50,75));
            break;
        case Qt::Key_S :
        case Qt::Key_Down :
            this->KeyDown = true;
            setPixmap(pix->copy(0,640,50,75));
            break;
        case Qt::Key_Space :
            sonar();
            break;
    }
    this->movePlayer();
}

void MyCharacter::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A :
    case Qt::Key_Left :
        this->KeyLeft = false;
        break;
    case Qt::Key_D :
    case Qt::Key_Right :
        this->KeyRight = false;
        break;
    case Qt::Key_W :
    case Qt::Key_Up :
        this->KeyUp = false;
        break;
    case Qt::Key_S :
    case Qt::Key_Down :
        this->KeyDown = false;
        break;
    }
    this->movePlayer();
}

void MyCharacter::movePlayer()
{
    if (this->KeyLeft){
        if(!mapParsor->doesPlayerCollide(QPoint(x()-speed, y()),QRect())){
            setPos(x()-speed, y());
        }else{
            touched();
        }
    }
    if(this->KeyRight){
        if(!mapParsor->doesPlayerCollide(QPoint(x()+speed + 25 , y()),QRect())) {
         setPos(x()+speed, y());
        }else{
            touched();
        }
    }
    if (this->KeyDown){
        if(!mapParsor->doesPlayerCollide(QPoint(x(), y()+speed+25),QRect())) {
            setPos(x(), y()+speed);
        }else{
            touched();
        }
    }
    if (this->KeyUp){
        if(!mapParsor->doesPlayerCollide(QPoint(x(), y()-speed),QRect())){

        setPos(x(), y()-speed);
        }else{
            touched();
        }
    }
}

void MyCharacter::updateEnv()
{
    this->movePlayer();
    sonarPower->update();
    qDebug() << mapParsor->layers->value("Ground")->getTilePropretyByPos(x()+25,y()+25);
}

void MyCharacter::sonar()
{
    sonarPower->fire();
}

void MyCharacter::touched()
{
    pix = new QPixmap(":/img/character/redballhalo.png");
    setPixmap(pix->copy(0,0,50,75));
    hitAnimationTimer = new QTimer();

    connect(hitAnimationTimer, SIGNAL(timeout()), this, SLOT(animationTouched()));
    hitAnimationTimer->start();
    hitAnimationTimer->setInterval(500);
}
void MyCharacter::animationTouched()
{
    pix = new QPixmap(":/img/character/blueballhalo.png");
    setPixmap(pix->copy(0,0,50,75));
    hitAnimationTimer->stop();

}
