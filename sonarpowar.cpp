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

/**
 * @brief Enclenchement du sonar
 */
void SonarPowar::fire(){

    if(!this->isFired)
    {
        QPixmap pix = QPixmap(":img/character/sonar.png");
        pixSize = pix.size().width();
        circle = new QGraphicsPixmapItem(pix);
        circle->setX(player->x()+0.5*player->pixSize);
        circle->setY(player->y()+0.5*player->pixSize);
        circle->setZValue(10);
        circle->setTransformOriginPoint(0.5*pixSize,0.5*pixSize);
        animIter = 0.0;
        isAnimFinished = false;
        scene->addItem(circle);
        this->isFired = true;
    }
}

/**
 * @brief Mise à jour de l'aniation + capture du sonar
 */
void SonarPowar::update(){
    if(this->isFired)
    {
        //Supprime le sonar et cercle précédent
        circle->setScale(animIter);
        scene->removeItem(sonarView);
        delete sonarView;//Soulage la mémoire, car sinon serait supprimer à la fin de l'application

        //Créer une nouvelle capture adapté au scale actuel(animIter), celle doit être reprise à chaque fois
        //Car l'image change suivant la taille du scale !!
        sonarView = new QGraphicsPixmapItem(mapParsor->layers->value("Ground")->getLayerImgCopy(
                (player->x()+0.5*player->pixSize)-0.5*pixSize*animIter,
                (player->y()+0.5*player->pixSize)-0.5*pixSize*animIter,
                pixSize*animIter,
                pixSize*animIter,
                QPixmap(":/img/character/sonarmask.png")
        ));

        //Positions du sonar & cercle, ceux ci doivent être décaler pour être centré par rapport au personnage
        int sonarXPos  = (player->pos().x()+0.5*player->pixSize) - sonarView->pixmap().size().width()   /2;
        int sonarYPos  = (player->pos().y()+0.5*player->pixSize) - sonarView->pixmap().size().height()  /2;
        int circleXPos = (player->pos().x()+0.5*player->pixSize) - circle->pixmap().size().width()      /2;
        int circleYPos = (player->pos().y()+0.5*player->pixSize) - circle->pixmap().size().height()     /2;
        sonarView->setPos(sonarXPos,sonarYPos);
        circle->setPos(circleXPos,circleYPos);

        //Ajoute la nouvelle capture
        scene->addItem(sonarView);

        //Animation, à remplacer par un sinus pour simplifier par la suite
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
