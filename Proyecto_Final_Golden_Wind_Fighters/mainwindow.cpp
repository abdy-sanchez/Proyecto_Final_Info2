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

    ui->nueva_partida->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , (GAME->tam_Y/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

    ui->cargar_partida->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 3*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty ) ;

        //Boton Regresar

    ui->regresar->setGeometry( 20 , (GAME->tam_Y) - 70 , 50 , 50 ) ;

    ui->regresar->hide() ;

        //Botonos cargar y nueva partida

    ui->nueva_partida->hide() ;

    ui->cargar_partida->hide() ;


        //Linea para Ingresar el nombre

    ui->agregar_nombre->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 6*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

    ui->agregar_nombre->hide() ;

        //Boton aceptar

    ui->aceptar->setGeometry( (GAME->tam_X/2)-(GAME->btx/2) , ((GAME->tam_Y + 9*(GAME->bty))/2)-(GAME->bty/2) , GAME->btx , GAME->bty );

    ui->aceptar->hide() ;


        //texto pregunta

    ui->texto1->setGeometry( 300 , 250 , 200 , 50 );

    ui->texto1->hide() ;

        //Configuracion de la musica de menu

    music = new QMediaPlayer() ;

    music->setMedia( QUrl("qrc:/Recursos/giornos-theme.mp3") ) ;

    music->setVolume(30) ;

    music->play() ;


        //Vonfiguracion sonido de lso botones

    efecto_boton_click = new QSoundEffect ;

    efecto_boton_click->setSource( QUrl("qrc:/Recursos/hit-01.wav") );

    efecto_boton_click->setVolume( 0.20f ) ;


}

MainWindow::~MainWindow()
{
    delete ui;

    delete  GAME ;

    delete  escena_menu ;

    delete  music ;

    delete efecto_boton_click ;

}


void MainWindow::on_Jugar_clicked(){

    efecto_boton_click->play() ;

    ui->Jugar->hide() ;

    ui->Multijugador->hide() ;

    ui->Salir->hide() ;

    ui->regresar->show() ;

    ui->nueva_partida->show() ;

    ui->cargar_partida->show() ;

    GAME->val_btn_presionado = 0 ;


}

void MainWindow::on_regresar_clicked(){

    efecto_boton_click->play() ;

    ui->Jugar->show() ;

    ui->Multijugador->show() ;

    ui->Salir->show() ;

    ui->regresar->hide() ;

    ui->nueva_partida->hide() ;

    ui->cargar_partida->hide() ;

    ui->agregar_nombre->hide() ;

    ui->aceptar->hide() ;

    ui->texto1->hide() ;





}

void MainWindow::on_Salir_clicked(){

    efecto_boton_click->play() ;

    msg_box = new QMessageBox ;

        //Configuracion basica del recuadro de salida

    msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

    msg_box->setWindowTitle("Golden Wind Fighters") ;

    msg_box->setText( "Seguro que deseas Salir?" ) ;

    msg_box->setStandardButtons( QMessageBox::Ok | QMessageBox::Cancel );

    msg_box->setDefaultButton(QMessageBox::Cancel);

    int opcion = msg_box->exec() ;

    switch( opcion ){

        case QMessageBox::Ok:

            QApplication::quit() ;      //Comando para cerrar el juego

        break;

        case QMessageBox::Cancel:

            //No hace na en especial, solo quita el recuadro

        break;

    }


}

void MainWindow::on_Multijugador_clicked(){

    efecto_boton_click->play() ;

    ui->Jugar->hide() ;

    ui->Multijugador->hide() ;

    ui->Salir->hide() ;

    ui->regresar->show() ;

    ui->nueva_partida->show() ;

    ui->cargar_partida->show() ;

    GAME->val_btn_presionado = 1 ;


}

void MainWindow::on_nueva_partida_clicked(){

    efecto_boton_click->play() ;

    ui->nueva_partida->hide() ;

    ui->agregar_nombre->show() ;

    ui->cargar_partida->hide() ;

    ui->aceptar->show() ;

    ui->texto1->show() ;

    switch ( GAME->val_btn_presionado ){

        case 0:{        //1 jugador



        }break;

        case 1:{        //multijugador



        }break;

    }


}

void MainWindow::on_cargar_partida_clicked(){

    efecto_boton_click->play() ;



    ui->aceptar->show() ;

    switch ( GAME->val_btn_presionado ){

        case 0:{        //1 jugador



        }break;

        case 1:{        //multijugador



        }break;

    }


}



void MainWindow::on_aceptar_clicked(){

    efecto_boton_click->play() ;

    GAME->nombre_jugador = ui->agregar_nombre->text() ;

    QFile archivo( "guardado.txt" ) ;           //meter todo esto en una funcion!!!

    archivo.open( QIODevice::WriteOnly | QIODevice::Text) ; //el archivo sobre escribe (cambiar)

    QTextStream out( &archivo );

    out << GAME->nombre_jugador << " N:" << GAME->nivel_jugador << " P:" << GAME->puntos_jugador << ";" ;

    out << "\n" ;


    archivo.close() ;

    ui->agregar_nombre->hide() ;

    ui->aceptar->hide() ;

    ui->texto1->hide() ;

    ui->regresar->hide() ;


}