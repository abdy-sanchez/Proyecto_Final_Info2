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


        //texto pregunta, nueva partida, cargar partida

    ui->texto1->setGeometry( 300 , 250 , 200 , 50 );

    ui->texto1->hide() ;

    ui->new_partida_txt->setGeometry( 283 , 200 , 230 , 50 ) ;

    ui->new_partida_txt->hide() ;

    ui->load_partida_txt->setGeometry( 283 , 200 , 230 , 50 ) ;

    ui->load_partida_txt->hide() ;

        //Configuracion de la musica de menu

    music = new QMediaPlayer() ;

    music->setMedia( QUrl("qrc:/Recursos/giornos-theme.mp3") ) ;

    music->setVolume(30) ;

    music->play() ;


        //Configuracion de la musica del juego

    msc_2 = new QMediaPlayer() ;

    msc_2->setMedia( QUrl("qrc:/Recursos/Fighting_Gold.mp3") ) ;

    msc_2->setVolume( 10 ) ;


        //Vonfiguracion sonido de lso botones

    efecto_boton_click = new QSoundEffect ;

    efecto_boton_click->setSource( QUrl("qrc:/Recursos/hit-01.wav") );

    efecto_boton_click->setVolume( 0.20f ) ;


}

void MainWindow::Guardar_nuevo_jugador(){


    GAME->nombre_jugador = ui->agregar_nombre->text() ;

    QFile archivo( "guardado.txt" ) ;

    archivo.open( QFile::Append | QFile::Text) ;

    QTextStream out( &archivo );


    QFile arch_2( "guardado.txt" ) ;

    GAME->existente_name = true ;

    if( arch_2.open( QFile::ReadOnly | QFile::Text ) ){

        QTextStream leer_name( &arch_2 ) ;

        while( !leer_name.atEnd() ){

            QString linea = leer_name.readLine();

            QString comparacion ;

            comparacion = linea.section(" " , 0 , 0 ) ;


            if( comparacion == GAME->nombre_jugador.replace( " ", "_" ) ){

                    GAME->existente_name = false ;
            }

        }//fin while

        arch_2.close() ;

    }//fin if arch2


    if( GAME->existente_name ){


        out << GAME->nombre_jugador.replace( " ", "_" ) << " N:" << GAME->nivel_jugador << " P:" << GAME->puntos_jugador << ";" ;

        out << "\n" ;

    }
    else{

        msg_box = new QMessageBox ;

        msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

        msg_box->setWindowTitle("ERROR") ;

        msg_box->setText( "El Nombre (" + GAME->nombre_jugador + ") Ya Existe..." ) ;

        msg_box->exec() ;

        delete msg_box ;
    }



    archivo.close() ;

}

void MainWindow::Cargar_partida_1jugador(){

    GAME->nombre_jugador = ui->agregar_nombre->text() ;

    QFile archivo_leer( "guardado.txt" ) ;

    if( archivo_leer.open( QFile::ReadOnly | QFile::Text ) ){

        QTextStream in( &archivo_leer ) ;



        while( !in.atEnd() ){

            QString linea = in.readLine();

            QString comparacion ;

            comparacion = linea.section(" " , 0 , 0 ) ;


            if( comparacion == GAME->nombre_jugador.replace( " ", "_" ) ){

                GAME->encontrado = true ;

            }



        }

        archivo_leer.close() ;
    }
    else{

        //msgBox diciendo que no hay archivo de partidas

        msg_box = new QMessageBox ;

        msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

        msg_box->setWindowTitle("ERROR") ;

        msg_box->setText( "NO SE ENCONTRO ARCHIVO DE PARTIDAS GUARDADAS" ) ;

        msg_box->exec() ;

        delete msg_box ;

    }

}



MainWindow::~MainWindow()
{
    delete ui;

    delete  GAME ;

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

    ui->new_partida_txt->hide() ;

    ui->load_partida_txt->hide() ;



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

            delete msg_box ;

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



    ui->cargar_partida->hide() ;





    switch ( GAME->val_btn_presionado ){

        case 0:{        //1 jugador

            ui->agregar_nombre->show() ;

            ui->aceptar->show() ;

            ui->texto1->show() ;

            ui->new_partida_txt->show() ;

            GAME->condicion_aceptar = true ;

        }break;

        case 1:{        //multijugador



        }break;

    }


}

void MainWindow::on_cargar_partida_clicked(){

    efecto_boton_click->play() ;

    ui->cargar_partida->hide() ;

    ui->nueva_partida->hide() ;


    switch ( GAME->val_btn_presionado ){

        case 0:{        //1 jugador

            ui->load_partida_txt->show() ;

            ui->texto1->show() ;

            ui->aceptar->show() ;

            ui->agregar_nombre->show() ;

            GAME->condicion_aceptar = false ;

        }break;

        case 1:{        //multijugador



        }break;

    }


}

void MainWindow::set_interfaz_1(){

    ui->agregar_nombre->hide() ;

    ui->aceptar->hide() ;

    ui->texto1->hide() ;

    ui->regresar->hide() ;

    music->stop() ;

    msc_2->play() ;

    ui->graphicsView->setBackgroundBrush( Qt::black ) ;

    ui->new_partida_txt->hide() ;

    ui->load_partida_txt->hide() ;

}



void MainWindow::on_aceptar_clicked(){

    efecto_boton_click->play() ;




    if( GAME->condicion_aceptar ){


        Guardar_nuevo_jugador() ;

        if( GAME->existente_name ){

            set_interfaz_1() ;

            nivel_1() ;
        }

    }
    else{


            Cargar_partida_1jugador() ;

            if( GAME->encontrado ){

                set_interfaz_1() ;

            }
            else{

                msg_box = new QMessageBox ;

                msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

                msg_box->setWindowTitle("NO ENCONTRADO") ;

                msg_box->setText( "El Nombre Ingresado (" + GAME->nombre_jugador + ") NO Existe..."  ) ;

                msg_box->exec() ;

                delete msg_box ;


            }


    }


}



void MainWindow::nivel_1(){

    ui->fondo_L1->setGeometry( 0 , 0 , GAME->tam_X , GAME->tam_Y ) ;

    nivel_1_fondo = new QMovie( ":/Recursos/mountains.gif" ) ;

    ui->fondo_L1->setMovie( nivel_1_fondo ) ;

    nivel_1_fondo->start() ;



}
