#include "mycharacter.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QDebug>

MyCharacter::MyCharacter(int x, int y,QGraphicsScene* parent,TiledJsonMapParsor *mapParsor)
{

    //this->mapParsor = mapParsor;
    this->setX(x);
    this->setY(y);
    pix = new QPixmap(":/img/character/blueballhalo.png");
    setPixmap(pix->copy(0,0,50,75));
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

    //Attention, on devra prendre un compte la puissance de la mahcine ici
    //Sinon le personnage ne se déplacera pas à la même vitesse sur n'importe quel machine
    if (this->KeyLeft) setPos(x()-1, y());
      else if (this->KeyRight) setPos(x()+1, y());;
    if (this->KeyDown) setPos(x(), y()+1);
      else if (this->KeyUp) setPos(x(), y()-1);
}

void MyCharacter::updateEnv()
{
    this->movePlayer();
    sonarPower->update();
    qDebug() << "hello";
}

void MyCharacter::sonar()
{
    sonarPower->fire();
}
void MyCharacter::nextFrame()
{

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
    qDebug() << "HFUEshfuihsuifhnsuiehbfuiebsufhbusebfusehfusebuj" << endl;
    hitAnimationTimer->stop();

}
