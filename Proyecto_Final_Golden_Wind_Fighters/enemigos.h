#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

class enemigos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    enemigos( int n_enemy );

    void set_enemigo() ;

    int frame = 0 ;

public slots:

    void movimiento_enemigos() ;

    void muerte() ;

private:

    QPixmap sprites1, enemy ;

    int tX , tY , n ;

    QTimer *timer_enemy ;

    QList<QGraphicsItem*> colisiones ;
};

#endif // ENEMIGOS_H
