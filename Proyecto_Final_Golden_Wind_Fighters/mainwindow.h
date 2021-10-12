#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QIcon>
#include "juego.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void setMenu();     //Atributo para mostrar el menu

    ~MainWindow();

private slots:

    void on_Jugar_clicked();

    void on_regresar_clicked();

    void on_Salir_clicked();

    void on_Multijugador_clicked();

    void on_nueva_partida_clicked();

    void on_cargar_partida_clicked();

private:

    Ui::MainWindow *ui;

    juego *GAME ;

    QGraphicsScene *escena_menu ;

    QMediaPlayer *music ;

    QSoundEffect *efecto_boton_click ;

    QMessageBox * msg_box ;


};
#endif // MAINWINDOW_H
