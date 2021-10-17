#ifndef JUGADOR_1_H
#define JUGADOR_1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Jugador_1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Jugador_1( int n );

    void set_imagen_jugador( int n );

private:

    QPixmap sprite_jugador , sprite_actual ;

};

#endif // JUGADOR_1_H
