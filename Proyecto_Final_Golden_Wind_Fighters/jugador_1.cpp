#include "jugador_1.h"

Jugador_1::Jugador_1( int n ){

    //n == 0 ->Avion morado ; n== 1 -> avion azul

    switch( n ){

        case 0:{

            sprite_jugador.load(":/Recursos/avion.png") ;

        }break;

        case 1:{

            sprite_jugador.load(":/Recursos/mistaplane.png") ;

        }break;

    }


}

void Jugador_1::set_imagen_jugador( int n ){

    switch( n ){

        case 0:{

            setPixmap( sprite_jugador.scaled( 64 , 48 ) ) ;

        }break;

        case 1:{

            sprite_actual = sprite_jugador.copy( 0 , 0 , 64 , 48 ) ;

            setPixmap( sprite_actual.scaled( 64 , 48 ) ) ;

        }break;

    }

}
