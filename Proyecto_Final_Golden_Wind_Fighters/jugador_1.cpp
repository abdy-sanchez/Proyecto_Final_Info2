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
