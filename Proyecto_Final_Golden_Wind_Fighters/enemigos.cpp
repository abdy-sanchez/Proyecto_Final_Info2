#include "enemigos.h"
#include "proyectil.h"

extern int puntos ;

enemigos::enemigos( int n_enemy ){

    if( n_enemy == 0 ){

        sprites1.load(":/Recursos/New_enemigo_1.png") ;

        tX = 61 ;

        tY = 50 ;

        n = 0 ;
    }
    else if( n_enemy == 1 ){

        sprites1.load(":/Recursos/new_enemigo_2.png") ;

        tX = 60 ;

        tY = 50 ;

        n = 1 ;
    }
    else if( n_enemy == 2 ){

        sprites1.load(":/Recursos/new_enemigo_3.png") ;

        tX = 62 ;

        tY = 58 ;

        n = 2 ;
    }

    timer_enemy = new QTimer() ;

    connect( timer_enemy , SIGNAL( timeout() ) , this , SLOT( movimiento_enemigos() ) ) ;

    timer_enemy->start( 30 ) ;

}

void enemigos::set_enemigo(){

    if( n == 0 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }
    else if( n == 1 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }
    else if( n == 2 ){

        enemy = sprites1.copy( tX*frame , 0 , tX , tY ) ;

    }

    setPixmap( enemy.scaled( tX , tY ) ) ;
}



void enemigos::movimiento_enemigos(){

        //colisiones

    colisiones = collidingItems() ;

    for( int i = 0 , nl = colisiones.size() ; i < nl ; i++ ){


        if( typeid( *( colisiones[i] )  ) ==  typeid( proyectil ) ){

            puntos = puntos + 500 ;

            scene()->removeItem( colisiones[i] ) ;

            delete colisiones[i] ;

            frame = 1 ;

            set_enemigo() ;

            QTimer::singleShot( 800 , this, SLOT( muerte() ) );

            return;

        }


    }

    int px , py ;

    px = this->x() ;

    py = this->y() ;

    setPos( px - 5 , py ) ;

    int flag = this->x() + 62 ;

    if( flag < 0 ){

        scene()->removeItem( this ) ;

        delete this ;
    }

}

void enemigos::muerte(){

    scene()->removeItem( this ) ;

    delete this ;

    return;
}
