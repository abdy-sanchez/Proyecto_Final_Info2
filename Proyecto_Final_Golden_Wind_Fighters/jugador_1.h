#ifndef JUGADOR_1_H
#define JUGADOR_1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QDebug>

class Jugador_1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Jugador_1( int n );     //Constructor del objeto, se le debe pasar el # del avion del jugador

    void set_imagen_jugador( int n );   //Funcion para setear las diferentes imagenes del avion

    int frame = 0 , num_plane ;     //Variables utiles para la animacion del avion

    int vel_0y = 1 , vel_0x = 2 , G = 1 , pos_0x , pos_0y , T = 50  ;

    bool GAME_OVER = false ;


    unsigned long long n = 0 ;

public slots:

    void animacion_sprite() ;       //Slot para la animacion del avion

    void caida_libre_avion() ;

private:

    QPixmap sprite_jugador , sprite_actual ;        //Aqui se guardan los sprites del avion

    QTimer *animacion, *caida_libre ;     //Timer para la animacion del avion



};

#endif // JUGADOR_1_H
