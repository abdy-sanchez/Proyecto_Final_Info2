#ifndef JUGADOR_1_H
#define JUGADOR_1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Jugador_1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Jugador_1( int n );     //Constructor del objeto, se le debe pasar el # del avion del jugador

    void set_imagen_jugador( int n );   //Funcion para setear las diferentes imagenes del avion

    int frame = 0 , num_plane ;     //Variables utiles para la animacion del avion

public slots:

    void animacion_sprite() ;       //Slot para la animacion del avion

private:

    QPixmap sprite_jugador , sprite_actual ;        //Aqui se guardan los sprites del avion

    QTimer *animacion ;     //Timer para la animacion del avion

};

#endif // JUGADOR_1_H
