#include "gamehud.h"
#include <QtWidgets>


GameHUD::GameHUD()
{


    // init HUD
    sonars = new QList<QPixmap>;
    sonars->push_front(QPixmap(":/img/hud/sonarA.png"));
    sonars->push_front(QPixmap(":/img/hud/sonarA.png"));




    // Personal font Use
    QFontDatabase::addApplicationFont(":/fonts/dicishandwrite.ttf");
    QFont *dicisHUD = new QFont("DicisHandwrite", 20);

    // Construction of the playtime group
    picChrono = new QGraphicsPixmapItem(QPixmap(":/img/hud/chrono.png"));
    picChrono->setPos(20,20);

    txtPlaytime = new QGraphicsTextItem("Temps de jeu");
    txtPlaytime->setDefaultTextColor(Qt::white); // Text Color
    txtPlaytime->setFont(*dicisHUD);
    txtPlaytime->setPos(90, 20);



    // Construction of the level group
    picLevel = new QGraphicsPixmapItem(QPixmap(":/img/hud/level.png"));
    picLevel->setPos(50,530);

    txtLevel = new QGraphicsTextItem("Niveau");
    txtLevel->setDefaultTextColor(Qt::white); // Text Color
    txtLevel->setFont(*dicisHUD);
    txtLevel->setPos(110, 550);

    txtCheck = new QGraphicsTextItem("Checkpoints");
    txtCheck->setDefaultTextColor(Qt::white); // Text Color
    txtCheck->setFont(*dicisHUD);
    txtCheck->setPos(50, 600);

/*
    for(int i = 0; i <= 4; i++){
        QGraphicsPixmapItem *picCheckA = new QGraphicsPixmapItem(QPixmap(":/img/hud/checkA.png"));
        picCheckA->setPos(50 + (spacing*i),640);
        this->level->addToGroup(picCheckA);
    }

    for(int i = 0; i <= 3; i++){
        QGraphicsPixmapItem *picCheckI = new QGraphicsPixmapItem(QPixmap(":/img/hud/checkI.png"));
        picCheckI->setPos(50 + (4*spacing) + (spacing*i),640);
        this->level->addToGroup(picCheckI);
    }
    */

    // Construction of the player group
    txtPlayer = new QGraphicsTextItem("Player");
    txtPlayer->setDefaultTextColor(Qt::white); // Text Color
    txtPlayer->setFont(*dicisHUD);
    txtPlayer->setPos(1000, 20);


    // Construction of the Sonar Group
    txtSonarEmission = new QGraphicsTextItem("Sonar Emissions");
    txtSonarEmission->setDefaultTextColor(Qt::white); // Text Color
    txtSonarEmission->setFont(*dicisHUD);
    txtSonarEmission->setPos(1000, 600);

    /*
    for(int i = 0; i <= 3; i++){
        QGraphicsPixmapItem *sonarA = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarA.png"));
        sonarA->setPos(1200 - (spacing*i),640);
        this->addToGroup(sonarA);
    }
    */

    /*
    for(int i = 0; i <= 4; i++){
        QGraphicsPixmapItem *sonarI = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarI.png"));
        sonarI->setPos(1200 - (4*spacing) - (spacing*i),640);
        this->addToGroup(sonarI);
    }
*/

    this->addToGroup(picChrono);
    this->addToGroup(txtPlaytime);

    this->addToGroup(picLevel);
    this->addToGroup(txtLevel);
    this->addToGroup(txtCheck);

    this->addToGroup(txtSonarEmission);

    this->updateSonar(10, 5);
    //this->updateSonar(10, 4);
    this->updateSonar(10, 9);


// http://doc.qt.io/qt-5/qgraphicslinearlayout.html
// http://www.qtcentre.org/threads/33998-Issue-in-placing-the-QGraphicsItems-into-QGraphicsLayout
//http://doc.qt.io/qt-5/qtwidgets-graphicsview-basicgraphicslayouts-example.html
}

// Init method

// Update method
void GameHUD::updateSonar(int max, int left){

    int spacing = 32;

    // Inactive init
    for(int i = 1; i <= max; i++){
        QGraphicsPixmapItem *sonarI = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarI.png"));
        sonarI->setPos(1200 - (spacing*i),640);
        this->addToGroup(sonarI);
    }

    int j = 0;
    foreach(QPixmap pic, *sonars){
        j++;
        QGraphicsPixmapItem *sonarA = new QGraphicsPixmapItem(pic);
        sonarA->setPos(1200 - (spacing*j),640);
        this->addToGroup(sonarA);
    }
}




// Push Methods
/*void GameHUD::pushSonar(){
    this->playtime->childItems().first()->setScale(3);
}

void GameHUD::pushCheckpoint(){}

*/
