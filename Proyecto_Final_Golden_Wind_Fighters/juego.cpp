#include "juego.h"

juego::juego(){


}

void juego::escena_Menu(){

    menu = new QGraphicsScene ;

    menu->setSceneRect(0 , 0 , tam_X , tam_Y );

    menu->setBackgroundBrush(QImage(":/Recursos/Fondo-Menu.jpg").scaled( tam_X ,tam_Y ) );

}
