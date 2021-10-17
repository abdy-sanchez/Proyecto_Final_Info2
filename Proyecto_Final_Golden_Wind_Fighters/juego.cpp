#include "juego.h"

juego::juego(){


}

void juego::escena_Menu(){

    menu = new QGraphicsScene ;

    menu->setSceneRect(0 , 0 , tam_X , tam_Y );

    menu->setBackgroundBrush(QImage(":/Recursos/Fondo-Menu.jpg").scaled( tam_X ,tam_Y ) );

}

void juego::set_level_one(){

    level_one = new QGraphicsScene ;

    level_one->setSceneRect( 0 , 0 , tam_X , tam_Y );

    Main_player = new Jugador_1( select_plane ) ;

    Main_player->set_imagen_jugador( select_plane ) ;

    Main_player->setX( 38 ) ;

    Main_player->setY( 240 ) ;


}

