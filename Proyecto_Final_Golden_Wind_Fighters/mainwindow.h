#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QIcon>
#include "juego.h"
#include "jugador_1.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QMessageBox>
#include <QFile>
#include <QMovie>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void setMenu();     //Atributo para mostrar el menu

    void Guardar_nuevo_jugador() ;

    void Cargar_partida_1jugador() ;

    void nivel_1() ;

    ~MainWindow();

private slots:

    void on_Jugar_clicked();

    void on_regresar_clicked();

    void on_Salir_clicked();

    void on_Multijugador_clicked();

    void on_nueva_partida_clicked();

    void on_cargar_partida_clicked();

    void set_interfaz_1() ;


    void on_aceptar_clicked();

private:

    Ui::MainWindow *ui;

    juego *GAME ;

    QMediaPlayer *music , *msc_2 ;

    QSoundEffect *efecto_boton_click ;

    QMessageBox * msg_box ;

    QMovie *nivel_1_fondo ;

    QGraphicsScene *escena_level ;

};
#endif // MAINWINDOW_H
