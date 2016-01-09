#ifndef GAMEHUD_H
#define GAMEHUD_H

#include <QtWidgets>

class GameHUD : public QGraphicsItemGroup
{
public:
    GameHUD();

private:

    // For the playtime (top left corner)
    QGraphicsPixmapItem *picChrono;
    QGraphicsTextItem *txtPlaytime;

    // For the player (top right corner)
    QGraphicsTextItem *txtPlayer;

    // For the level + checkpoints (bottom left corner)
    QGraphicsPixmapItem *picLevel;
    QGraphicsTextItem *txtLevel;
    QGraphicsTextItem *txtCheck;

    // For the sonar (bottom right corner)
    QGraphicsTextItem *txtSonarEmission;

    // List of sonar
    QList<QPixmap> *sonars;
    QList<QPixmap*> *checkpoints;

public slots:

    // Update elements
    //void update();              // Update all HUD elements (call all the update methods)
    //void updateTime();
    //void updateSonar();
    //void updatePlayer();
    //void updateCheckpoints();

    void initHUD();
    void updateCheckpoints();
    void updateSonar(int, int);

    // Push new element
    //void pushSonar();
    //void pushCheckpoint();

    // Pop elem
    //void popSonar();
    //void popCheckpoint();

};

#endif // GAMEHUD_H
