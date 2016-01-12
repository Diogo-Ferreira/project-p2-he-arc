#include "sonarpowar.h"
#include "mycharacter.h"
#include "tiledjsonmapparsor.h"
SonarPowar::SonarPowar(QGraphicsScene* scene,MyCharacter *player,TiledJsonMapParsor *mapParsor)
{
    this->scene = scene;
    this->player = player;
    this->mapParsor = mapParsor;
    this->isFired = false;
    sonarView = new QGraphicsPixmapItem();
    circle = new QGraphicsPixmapItem();
}


void SonarPowar::fire(){

    if(!this->isFired)
    {
        QPixmap pix = QPixmap(":img/character/sonar.png");
        pixSize = pix.size().width();
        circle = new QGraphicsPixmapItem(pix);

        circle->setX(player->x()+0.5*player->pixSize);
        circle->setY(player->y()+0.5*player->pixSize);
        circle->setZValue(96);
        circle->setTransformOriginPoint(0.5*pixSize,0.5*pixSize);

        animIter = 0.00;
        isAnimFinished = false;
        scene->addItem(circle);
        this->isFired = true;
    }
}

void SonarPowar::update(){
    if(this->isFired)
    {
        circle->setScale(animIter);
        scene->removeItem(sonarView);
        delete sonarView;
        sonarView = new QGraphicsPixmapItem(mapParsor->layers->value("Ground")->getLayerImgCopy(
                            (player->x()+0.5*player->pixSize)-0.5*pixSize*animIter,
                            (player->y()+0.5*player->pixSize)-0.5*pixSize*animIter,
                            pixSize*animIter,
                            pixSize*animIter,
                            QPixmap(":/img/character/sonarmask.png")
                    ));
        sonarView->setPos((player->pos().x()+0.5*player->pixSize) - sonarView->pixmap().size().width()/2,(player->pos().y()+0.5*player->pixSize)- sonarView->pixmap().size().height()/2);
        circle->setPos((player->pos().x()+0.5*player->pixSize) - circle->pixmap().size().width()/2,(player->pos().y()+0.5*player->pixSize)- circle->pixmap().size().height()/2);
        scene->addItem(sonarView);
        if(isAnimFinished)
        {
            if(animIter > 1)
            {
                animIter -= animSpeed;
            }else{
                animIter -= animSpeed*10;
                if(animIter <= 0.5)
                {
                    scene->removeItem(circle);
                    scene->removeItem(sonarView);
                    isFired = false;
                }
            }
        }else if(!isAnimFinished){
            if(animIter > 1)
            {
                animIter += animSpeed;
            }else{
                animIter += animSpeed*3;
            }

            if(animIter > 1.5)
            {
                isAnimFinished = true;
            }
        }
    }
}
