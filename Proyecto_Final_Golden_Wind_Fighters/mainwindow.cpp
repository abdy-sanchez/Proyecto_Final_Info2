#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;        //Icono de la ventana

    GAME = new juego ;      //Creamos un objeto tipo juego

    setMenu();      //Ejecutamos la funcion que configura el menu

    srand(time(NULL)) ;     //Para poder generar un num aleatorio
}

void MainWindow::setMenu(){     //Funcion en la cual se inicializa y muestra el menu del juego


        //Configuracion de la escena

    GAME->escena_Menu();

    setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2) ;

    setMaximumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    setMinimumSize(GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    ui->graphicsView->setGeometry( 0, 0 , GAME->tam_X + 2 , GAME->tam_Y + 2 ) ;

    ui->graphicsView->setScene( GAME->menu );       //Añadimos la escena menu a la pantalla






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

    music->setVolume(30) ;      //Definimos el nivel del volumen de la musica

    music->play() ;





        //Configuracion de la musica del juego

    msc_2 = new QMediaPlayer() ;

    msc_2->setMedia( QUrl("qrc:/Recursos/Fighting_Gold.mp3") ) ;

    msc_2->setVolume( 10 ) ;





        //Configuracion sonido de los botones del menu

    efecto_boton_click = new QSoundEffect ;

    efecto_boton_click->setSource( QUrl("qrc:/Recursos/hit-01.wav") );

    efecto_boton_click->setVolume( 0.20f ) ;    //Definimos el nivel del volumen del efecto de sonido


        //configuracion botones seleccion avion

    ui->buttonGroup->setId( ui->avn1 , 1 ) ;        //Definimos un ID para identificar los botones de seleccion del avion
    ui->buttonGroup->setId( ui->avn2 , 2 ) ;

    ui->avn1->hide() ;
    ui->avn2->hide() ;

    ui->avn1->setGeometry( 470 , 322 , 80 , 20 ) ;
    ui->avn2->setGeometry( 470 , 338 , 80 , 20 ) ;


}

void MainWindow::Guardar_nuevo_jugador(){

        //Condiciones para elegir el avion

    if( ui->buttonGroup->button( 1 )->isChecked() ){        //Se revisa Qué Avion se elegió

       GAME->select_plane = 1 ;

    }else if( ui->buttonGroup->button( 2 )->isChecked() ){

       GAME->select_plane = 2 ;
    }
    else{

       GAME->select_plane = 1 ;     //Por defecto, pone el 1er avion
    }



    GAME->nombre_jugador = ui->agregar_nombre->text() ;     //Obtenemos el texto Ingresado por el usuario

    if( GAME->nombre_jugador == "" ){

       int random_num = rand()%1000 ;      //Si NO se ingreso un nombre, se pone Random# y un numero aleatorio

       GAME->nombre_jugador = "Random#" + QString::number( random_num , 10 ) ;

    }

    QFile archivo( "guardado.txt" ) ;

    archivo.open( QFile::Append | QFile::Text) ;        //Se abre o Crea el archivo donde se almacenará la informacion del jugador

    QTextStream out( &archivo );


    QFile arch_2( "guardado.txt" ) ;        //Tambien se abre el msimo archivo y se revisa que el nombre ingresado no exista

    GAME->existente_name = true ;

    if( arch_2.open( QFile::ReadOnly | QFile::Text ) ){

        QTextStream leer_name( &arch_2 ) ;

        while( !leer_name.atEnd() ){

            QString linea = leer_name.readLine();

            QString comparacion ;

            comparacion = linea.section(" " , 0 , 0 ) ;


            if( comparacion == GAME->nombre_jugador.replace( " ", "_" ) ){      //Se comparan los nombres existentes con el ingresado

                    GAME->existente_name = false ;
            }

        }//fin while

        arch_2.close() ;

    }//fin if arch2


    if( GAME->existente_name ){     //Si el nombre no existe anteriormente, es creado y guardado


        out << GAME->nombre_jugador.replace( " ", "_" ) << " Avn:" << GAME->select_plane << " N:" << GAME->nivel_jugador << " P:" << GAME->puntos_jugador << ";" ;

        out << "\n" ;

    }
    else{

        msg_box = new QMessageBox ;

        msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

        msg_box->setWindowTitle("ERROR") ;

        msg_box->setText( "El Nombre (" + GAME->nombre_jugador.replace("_"," ") + ") Ya Existe..." ) ;

        msg_box->exec() ;

        delete msg_box ;
    }



    archivo.close() ;

}

void MainWindow::Cargar_partida_1jugador(){

    GAME->nombre_jugador = ui->agregar_nombre->text() ;

    QFile archivo_leer( "guardado.txt" ) ;

    if( archivo_leer.open( QFile::ReadOnly | QFile::Text ) ){       //Se abre el archivo en busca de la coincidencia con el nombre ingresado

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



MainWindow::~MainWindow()       //Se eliminan lo punteros de la memoria al cerrar el programa
{
    delete ui;

    delete  GAME ;

    delete  music ;

    delete efecto_boton_click ;

    delete  msc_2 ;

    delete msg_box ;

}


void MainWindow::on_Jugar_clicked(){        //Al presionar el boton de 1 jugador

    efecto_boton_click->play() ;

    ui->Jugar->hide() ;

    ui->Multijugador->hide() ;

    ui->Salir->hide() ;

    ui->regresar->show() ;

    ui->nueva_partida->show() ;

    ui->cargar_partida->show() ;

    GAME->val_btn_presionado = 0 ;      //Se asigana 0 a la variable


}

void MainWindow::on_regresar_clicked(){     //Al presionar el boton de regresar



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

    ui->avn1->hide() ;

    ui->avn2->hide() ;



}

void MainWindow::on_Salir_clicked(){        //Al presionar el boton de salir


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

void MainWindow::on_Multijugador_clicked(){         //Al presionar el boton de multi jugador

    efecto_boton_click->play() ;

    ui->Jugar->hide() ;

    ui->Multijugador->hide() ;

    ui->Salir->hide() ;

    ui->regresar->show() ;

    ui->nueva_partida->show() ;

    ui->cargar_partida->show() ;

    GAME->val_btn_presionado = 1 ;      //Se le asigana 1 a la variable


}

void MainWindow::on_nueva_partida_clicked(){        //Al presionar el boton de nueva partida

    efecto_boton_click->play() ;

    ui->nueva_partida->hide() ;

    ui->cargar_partida->hide() ;



    switch ( GAME->val_btn_presionado ){        //Se revisa qué valor tiene la variable

        case 0:{        //1 jugador

            ui->agregar_nombre->show() ;

            ui->aceptar->show() ;

            ui->texto1->show() ;

            ui->new_partida_txt->show() ;

            ui->avn1->show() ;

            ui->avn2->show() ;

            GAME->condicion_aceptar = true ;

        }break;

        case 1:{        //multijugador



        }break;

    }


}

void MainWindow::on_cargar_partida_clicked(){       //Al presionar el boton de cargar partida

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

void MainWindow::set_interfaz_1(){      //Funcion que se ejecuta cuando el jueva va a comenzar (Esconde botones y demas)

    ui->agregar_nombre->hide() ;

    ui->aceptar->hide() ;

    ui->texto1->hide() ;

    ui->regresar->hide() ;

    music->stop() ;

    msc_2->play() ;

    ui->graphicsView->setBackgroundBrush( Qt::black ) ;

    ui->new_partida_txt->hide() ;

    ui->load_partida_txt->hide() ;

    ui->avn1->hide() ;

    ui->avn2->hide() ;

}



void MainWindow::on_aceptar_clicked(){      //Al presionar el boton de aceptar


    efecto_boton_click->play() ;


    if( GAME->condicion_aceptar ){


        Guardar_nuevo_jugador() ;

        if( GAME->existente_name ){     //Si se cumplen las condicones, el juego comienza en el nivel 1

            set_interfaz_1() ;

            nivel_1() ;
        }

    }
    else{


            Cargar_partida_1jugador() ;

            if( GAME->encontrado ){     //Si se cumplen las condiciones, se cargará la partida correspondiente

                set_interfaz_1() ;

            }
            else{

                msg_box = new QMessageBox ;

                msg_box->setWindowIcon( QIcon( ":/Recursos/GWfighterslogo.png" ) ) ;

                msg_box->setWindowTitle("NO ENCONTRADO") ;

                msg_box->setText( "El Nombre Ingresado (" + GAME->nombre_jugador.replace("_"," ") + ") NO Existe..."  ) ;

                msg_box->exec() ;

                delete msg_box ;


            }


    }


}

void MainWindow::perdiste(){

    if( GAME->Fin_partida ){

        msc_2->stop() ;

    }

}



void MainWindow::nivel_1(){     //Funcion para el nivel 1


    GAME->set_level_one() ;

    ui->graphicsView->setScene( GAME->level_one );

    end_game = new QTimer() ;

    connect( end_game , SIGNAL( timeout() ) , this , SLOT( perdiste() ) ) ;

    end_game->start( 10 ) ;

    delete  GAME->menu ;


}
