#ifndef GAMEHUD_H
#define GAMEHUD_H

#include <QtWidgets>

class GameHUD : public QGraphicsItemGroup
{
public:
    GameHUD();

    // This is so cool!

private:
    QGraphicsItemGroup *playtime;   // Playtime
    QGraphicsItemGroup *player;     // Actual player
    QGraphicsItemGroup *sonar;      // Sonar emissions left
    QGraphicsItemGroup *level;      // Level / Checkpoints
};

#endif // GAMEHUD_H
