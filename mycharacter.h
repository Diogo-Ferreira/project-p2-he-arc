#ifndef MYCHARACTER
#define MYCHARACTER

//#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>

class MyCharacter: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public :
    MyCharacter(int x, int y);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyRight = false;
    bool KeyLeft = false;
    bool personnage = true;
    QPixmap *pix;
    int id;
    QTimer *timer;
private :
public slots :
    void updateEnv();
    void sonar();
    void nextFrame();
    void touched();
    void animationTouched();
};

#endif // MYCHARACTER

