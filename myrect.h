#ifndef MYRECT
#define MYRECT

//#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>

class MyRect: public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public :
    MyRect();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void changeCharacter();
    void movePlayer();
    bool KeyUp = false;
    bool KeyDown = false;
    bool KeyRight = false;
    bool KeyLeft = false;
    bool personnage = true;
private :
public slots :
    void updateEnv();
};

#endif // MYRECT

