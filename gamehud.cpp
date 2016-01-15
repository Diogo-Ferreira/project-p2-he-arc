#include "gamehud.h"
#include <QtWidgets>



GameHUD::GameHUD()
{

    // HUD groups initialization
    this->playtime  =   new QGraphicsItemGroup();
    this->player    =   new QGraphicsItemGroup();
    this->sonar     =   new QGraphicsItemGroup();
    this->level     =   new QGraphicsItemGroup();

    // Personal fonts use
    QFontDatabase::addApplicationFont(":/fonts/dicishandwrite.ttf");
    QFont *dicisHUD = new QFont("DicisHandwrite", 20);
    QFont *dicisHUDBig = new QFont("DicisHandwrite", 50);

    // Construction of the playtime group
    QGraphicsPixmapItem *picChrono = new QGraphicsPixmapItem(QPixmap(":/img/hud/chrono.png"));
    picChrono->setPos(40,600);
    picChrono->setZValue(1);
    this->txtPlaytime = new QGraphicsTextItem("0");
    this->txtPlaytime->setDefaultTextColor(Qt::white); // Text Color
    this->txtPlaytime->setFont(*dicisHUD);
    this->txtPlaytime->setZValue(2);
    this->txtPlaytime->setPos(55, 615);

    // Construction of the player group
    QGraphicsTextItem *txtPlayer = new QGraphicsTextItem("Player");
    txtPlayer->setDefaultTextColor(Qt::white); // Text Color
    txtPlayer->setFont(*dicisHUD);
    txtPlayer->setPos(1100, 20);

    this->txtPlayerName = new QGraphicsTextItem("Ray");
    this->txtPlayerName->setDefaultTextColor(Qt::white); // Text Color
    this->txtPlayerName->setFont(*dicisHUDBig);
    this->txtPlayerName->setPos(1100, 40);

    // Construction of the Sonar Group
    QGraphicsTextItem *txtSonarEmission = new QGraphicsTextItem("Sonar Emissions");
    txtSonarEmission->setDefaultTextColor(Qt::white); // Text Color
    txtSonarEmission->setFont(*dicisHUD);
    txtSonarEmission->setPos(1000, 600);

    this->addToGroup(txtSonarEmission);

    this->playtime->addToGroup(txtPlaytime);
    this->playtime->addToGroup(picChrono);

    this->player->addToGroup(txtPlayer);
    this->addToGroup(txtPlayerName);

    // Add the playtime group to the HUD
    this->addToGroup(playtime);
    this->addToGroup(sonar);
    this->addToGroup(player);
}

/**
 * @brief  Met à jour le HUD (nombre de sonars) après une émission.
 * @param nbEmissions
 * @param nbEmissionsLeft
 */
void GameHUD::update(int nbEmissions, int nbEmissionsLeft){

    this->removeItems();

    int spacing = 34;

    // Update the sonar pixmaps elements
    for(int i = 1; i <= nbEmissionsLeft; i++){
        QGraphicsPixmapItem *sonarA = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarA.png"));
        sonarA->setPos(1200 - (spacing*i),640);
        this->sonar->addToGroup(sonarA);
    }

    if(nbEmissions - nbEmissionsLeft <= 0){
        nbEmissionsLeft = nbEmissions;
    }

    for(int i = 1; i <= nbEmissions - nbEmissionsLeft; i++){
        QGraphicsPixmapItem *sonarI = new QGraphicsPixmapItem(QPixmap(":/img/hud/sonarI.png"));
        sonarI->setPos(1200 - (nbEmissionsLeft*spacing) - (spacing*i),640);
        this->sonar->addToGroup(sonarI);
    }
}

/**
 * @brief Permet de supprimer les éléments HUD avant de les réafficher.
 */
void GameHUD::removeItems(){
    qDeleteAll(this->sonar->childItems());
}

/**
 * @brief Met à jour le nom du joueur après un changement.
 * @param name
 */
void GameHUD::updateName(QString name){
    this->txtPlayerName->setHtml(name);
}

/**
 * @brief Permet de mettre à jour le temps de jeu avec timer venant de gamescene.
 * @param time
 */
void GameHUD::updateTime(int time){
    QString s = QString::number(time);
    this->txtPlaytime->setHtml(s);
}
