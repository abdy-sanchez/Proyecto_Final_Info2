#ifndef JUEGO_H
#define JUEGO_H


#include <QObject>
#include <QGraphicsScene>
#include "jugador_1.h"

class juego: public QObject
{
    Q_OBJECT

    friend class MainWindow ;

public:

    juego();

    void escena_Menu();

    void set_level_one() ;


private:

    int tam_X = 800 , tam_Y = 500, pixelX = 64 , pixel_Y = 48 ;

    int btx = 120 , bty = 30 ;

    QGraphicsScene *menu, *level_one ;

    int val_btn_presionado, nivel_jugador = 1, puntos_jugador = 0 , select_plane = 0 ;

    QString nombre_jugador ;

    bool condicion_aceptar = true , encontrado = false , existente_name = true ;

    Jugador_1 *Main_player ;

};

#endif // JUEGO_H
