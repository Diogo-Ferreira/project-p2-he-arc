#include "gamehud.h"
#include <QtWidgets>


GameHUD::GameHUD(int nEmissions, int nCheckpoints)
{


    // HUD groups initialization
    this->playtime  =   new QGraphicsItemGroup();
    this->player    =   new QGraphicsItemGroup();
    this->sonar     =   new QGraphicsItemGroup();
    this->level     =   new QGraphicsItemGroup();

    // Values
    this->nbEmissions = nEmissions;
    this->nbCheckpoints = nCheckpoints;

    // Personal font Use
    QFontDatabase::addApplicationFont(":/fonts/dicishandwrite.ttf");
    QFont *dicisHUD = new QFont("DicisHandwrite", 20);

    // Construction of the playtime group
    QGraphicsPixmapItem *picChrono = new QGraphicsPixmapItem(QPixmap(":/img/hud/chrono.png"));
    picChrono->setPos(20,20);

    QGraphicsTextItem *txtPlaytime = new QGraphicsTextItem("Temps de jeu");
    txtPlaytime->setDefaultTextColor(Qt::white); // Text Color
    txtPlaytime->setFont(*dicisHUD);
    txtPlaytime->setPos(90, 20);

    // Construction of the level group
    QGraphicsPixmapItem *picLevel = new QGraphicsPixmapItem(QPixmap(":/img/hud/level.png"));
    picLevel->setPos(50,530);

    QGraphicsTextItem *txtLevel = new QGraphicsTextItem("Niveau");
    txtLevel->setDefaultTextColor(Qt::white); // Text Color
    txtLevel->setFont(*dicisHUD);
    txtLevel->setPos(110, 550);

    QGraphicsTextItem *txtCheck = new QGraphicsTextItem("Checkpoints");
    txtCheck->setDefaultTextColor(Qt::white); // Text Color
    txtCheck->setFont(*dicisHUD);
    txtCheck->setPos(50, 600);


    // Construction of the player group
    QGraphicsTextItem *txtPlayer = new QGraphicsTextItem("Player");
    txtPlayer->setDefaultTextColor(Qt::white); // Text Color
    txtPlayer->setFont(*dicisHUD);
    txtPlayer->setPos(1000, 20);


    // Construction of the Sonar Group
    QGraphicsTextItem *txtSonarEmission = new QGraphicsTextItem("Sonar Emissions");
    txtSonarEmission->setDefaultTextColor(Qt::white); // Text Color
    txtSonarEmission->setFont(*dicisHUD);
    txtSonarEmission->setPos(1000, 600);


    this->sonar->addToGroup(txtSonarEmission);

    this->playtime->addToGroup(txtPlaytime);
    this->playtime->addToGroup(picChrono);

    this->player->addToGroup(txtPlayer);

    this->level->addToGroup(txtLevel);
    this->level->addToGroup(txtCheck);
    this->level->addToGroup(picLevel);

    // Add the playtime group to the HUD
    this->addToGroup(playtime);
    this->addToGroup(level);
    this->addToGroup(sonar);
    this->addToGroup(player);


    // Init (premier update)
    this->update(this->nbEmissions, this->nbEmissions, this->nbCheckpoints, this->nbCheckpoints);
}


void GameHUD::init(){
}

void GameHUD::update(int nbEmissions, int nbEmissionsLeft, int nbCheckpoints, int nbCheckpointsLeft){

    this->removeItems();

    int spacing = 34;

    // Update the checkpoints pixmaps elements
    for(int i = 1; i <= nbCheckpointsLeft; i++){
        QGraphicsPixmapItem *picCheckA = new QGraphicsPixmapItem(QPixmap(":/img/hud/checkA.png"));
        picCheckA->setPos(50 + (spacing*i),640);
        this->level->addToGroup(picCheckA);
    }

    for(int i = 1; i <= nbCheckpoints - nbCheckpointsLeft; i++){
        QGraphicsPixmapItem *picCheckI = new QGraphicsPixmapItem(QPixmap(":/img/hud/checkI.png"));
        picCheckI->setPos(50 + (nbCheckpointsLeft*spacing) + (spacing*i),640);
        this->level->addToGroup(picCheckI);
    }

    // Update the sonar pixmaps elements
    for(int i = 1; i <= nbEmissionsLeft; i++){
        QGraphicsPixmapItem *sonarA = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarA.png"));
        sonarA->setPos(1200 - (spacing*i),640);
        this->sonar->addToGroup(sonarA);
    }

    for(int i = 1; i <= nbEmissions - nbEmissionsLeft; i++){
        QGraphicsPixmapItem *sonarI = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarI.png"));
        sonarI->setPos(1200 - (nbEmissionsLeft*spacing) - (spacing*i),640);
        this->sonar->addToGroup(sonarI);
    }
}

void GameHUD::removeItems(){

    qDeleteAll(this->sonar->childItems());

}


