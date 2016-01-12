#include "mycharacter.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include "tiledjsonmapparsor.h"

MyCharacter::MyCharacter(int x, int y,bool isSelected,QGraphicsScene* parent,TiledJsonMapParsor *mapParsor)
{

    this->mapParsor = mapParsor;
    this->setX(x);
    this->setY(y);
    this->isSelectedPlayer = isSelected;
    setImage(isSelected);
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
            break;
        case Qt::Key_D :
        case Qt::Key_Right :
            this->KeyRight = true;
            break;
        case Qt::Key_W :
        case Qt::Key_Up :
            this->KeyUp = true;
            break;
        case Qt::Key_S :
        case Qt::Key_Down :
            this->KeyDown = true;
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

void MyCharacter::setImage(bool isSelectedPlayer)
{
    if(isSelectedPlayer) setPixmap(QPixmap(":/img/character/blueballhalo.png"));
    else{
        setPixmap(QPixmap(":/img/character/blueballshadow.png"));
    }
    this->pixSize = this->pixmap().size().width();
}
void MyCharacter::stop(){
    KeyDown = false;
    KeyLeft = false;
    KeyRight = false;
    KeyUp = false;
}

void MyCharacter::updateEnv()
{
    this->movePlayer();
    sonarPower->update();
}

void MyCharacter::sonar()
{
    sonarPower->fire();
}

void MyCharacter::touched()
{
    setPixmap(QPixmap(":/img/character/redballhalo.png"));
    hitAnimationTimer = new QTimer();
    connect(hitAnimationTimer, SIGNAL(timeout()), this, SLOT(animationTouched()));
    hitAnimationTimer->start();
    hitAnimationTimer->setInterval(500);
}
void MyCharacter::animationTouched()
{
    setImage(this->isSelectedPlayer);
    hitAnimationTimer->stop();

}
