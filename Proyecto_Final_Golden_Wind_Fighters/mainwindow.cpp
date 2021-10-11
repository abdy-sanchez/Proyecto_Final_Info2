#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;        //Icono de la ventana

    GAME = new juego ;

    setMenu();

}

void MainWindow::setMenu(){     //Funcion en la cual se inicializa y muestra el menu del juego


        //Configuracion de la escena

    GAME->escena_Menu();

    setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2) ;

    setMaximumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    setMinimumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    ui->graphicsView->setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    ui->graphicsView->setScene( GAME->menu );



        //Configuracion de los botones principales

    ui->Jugar->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , (GAME->tam_Y/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

    ui->Multijugador->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 3*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty ) ;

    ui->Salir->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 6*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );


        //Configuracion de la musica de menu

    music = new QMediaPlayer() ;

    music->setMedia( QUrl("qrc:/Recursos/giornos-theme.mp3") ) ;

    music->setVolume(30) ;

    music->play() ;



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Jugar_clicked(){

    ui->Multijugador->hide() ;

    ui->Salir->hide() ;

}
