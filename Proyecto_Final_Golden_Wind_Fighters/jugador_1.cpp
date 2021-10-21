#include "jugador_1.h"

Jugador_1::Jugador_1( int n ){

    //n == 0 ->Avion morado ; n== 1 -> avion azul

    switch( n ){            //Alistamos los recursos necesarios para el sprite del jugador

        case 1:{

            sprite_jugador.load(":/Recursos/avn_p1.png") ;

        }break;

        case 2:{

            sprite_jugador.load(":/Recursos/mistaplane.png") ;

        }break;

    }

    num_plane = n ;     //Asiganamos el valor del sprite del avion

    animacion = new QTimer() ;

    connect( animacion , SIGNAL( timeout() ) , this , SLOT( animacion_sprite() ) ) ;

    animacion->start( 60 ) ;    //iniciamos el timer para la animacion del avion

    caida_libre = new QTimer() ;

    connect( caida_libre , SIGNAL( timeout() ) , this , SLOT( caida_libre_avion() ) ) ;

    caida_libre->start( T ) ;


}

void Jugador_1::set_imagen_jugador( int n ){

    switch( n ){            //Alistamos las imagenes del avion para ser mostradas en pantalla

        case 1:{

            sprite_actual = sprite_jugador.copy( 80*frame , 0 , 80 , 48 ) ;

            setPixmap( sprite_actual.scaled( 80 , 48 ) ) ;

        }break;

        case 2:{

            sprite_actual = sprite_jugador.copy( 64*frame , 0 , 64 , 48 ) ;

            setPixmap( sprite_actual.scaled( 64 , 48 ) ) ;

        }break;

    }

}

void Jugador_1::animacion_sprite(){

    frame++ ;
                            //Se ejecuta la animacion de cada avion
    if( frame == 3 ){

        frame = 0 ;

    }

    set_imagen_jugador( num_plane ) ;

}

void Jugador_1::caida_libre_avion(){

    float x , y ;

    pos_0x = this->x() ;

    pos_0y = this->y() ;

    x = pos_0x - vel_0x*n*( 0.001*T ) ;

    y =  pos_0y + vel_0y*n*( 0.001*T ) - 0.5*G*n*( 0.001*T )*( 0.001*T ) ;

    this->setPos( int( x ) , int( y ) ) ;

    n++ ;

    int condicion_GAME_OVER1  = this->x() + 40 ;

    int condicion_GAME_OVER2  = this->y() ;


    if( condicion_GAME_OVER1 < 0 || condicion_GAME_OVER2 > 468 ){

        qDebug() << "GAME OVER" ;

        caida_libre->stop() ;

        animacion->stop() ;

        GAME_OVER = true ;


    }


}
