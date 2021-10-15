#ifndef JUEGO_H
#define JUEGO_H


#include <QObject>
#include <QGraphicsScene>

class juego: public QObject
{
    Q_OBJECT

    friend class MainWindow ;

public:

    juego();

    void escena_Menu();

private:

    int tam_X = 800 , tam_Y = 500, pixelX = 64 , pixel_Y = 48 ;

    int btx = 120 , bty = 30 ;

    QGraphicsScene *menu ;

    int val_btn_presionado, nivel_jugador = 1, puntos_jugador = 0 ;

    QString nombre_jugador ;



};

#endif // JUEGO_H
