#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QGridLayout>
#include <math.h>
#include<QLabel>
#include <Archivo.h>
#include <QApplication>
#include<QtGui>
#include<QtCore>
#include<QLayout>
#include <math.h>
#include<QPushButton>
#include <math.h>
#include "clickablelabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&Don,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(dataInDaHouse(QByteArray)));
    win = new QWidget(this);
    win->resize(this->size());
    this->setCentralWidget(win);
    layout = new QGridLayout;

    win->setLayout(layout);
    mas = new QPushButton(this);
    //set size and location of the button
    mas->setGeometry(QRect( QPoint(1080, 10), QSize(50, 50) ));
    QIcon *icon = new QIcon("/home/abigail/Desktop/Proyecto1/Zoommas.png");
    mas->setIcon(*icon);
    mas->setStyleSheet("background-color: black");
    actual = 1;
    primero = new QPushButton(this);
    primero->setGeometry(40,980,35,20);
 connect(primero, SIGNAL (clicked()),this, SLOT (CambiarPagina1()));
    segundo = new QPushButton(this);
    segundo->setGeometry(80,980,35,20);
      connect(segundo, SIGNAL (clicked()),this, SLOT (CambiarPagina2()));
    tercero = new QPushButton(this);
    tercero->setGeometry(120,980,35,20);
     connect(tercero, SIGNAL (clicked()),this, SLOT (CambiarPagina3()));
    cuarto = new QPushButton(this);
    cuarto->setGeometry(160,980,35,20);
     connect(cuarto, SIGNAL (clicked()),this, SLOT (CambiarPagina4()));
    quinto = new QPushButton(this);
    quinto->setGeometry(200,980,35,20);
     connect(quinto, SIGNAL (clicked()),this, SLOT (CambiarPagina5()));
    flecha = new QPushButton(this);
    flecha->setGeometry(240,980,18,20);
    flecha->setText(">");
    connect(flecha,SIGNAL(clicked()),this,SLOT(Siguiente()));
    flechaAnterior = new QPushButton(this);
    flechaAnterior->setGeometry(10,980,18,20);
    flechaAnterior->setText("<");
    connect(flechaAnterior,SIGNAL(clicked()),this,SLOT(Anterior()));


    zoom = new int(9);


    //Connect button signal to appropriate slt
    connect(mas, SIGNAL (clicked()),this, SLOT (masBoton()));

    menos = new QPushButton(this);
    menos->setGeometry(QRect( QPoint(1080, 60), QSize(50, 50) ));
    QIcon *iconmen = new QIcon("/home/abigail/Desktop/Proyecto1/Zoommenos.png");
    menos->setIcon(*iconmen);
    menos->setStyleSheet("background-color: black");

    //Connect button signal to appropriate slot
    connect(menos, SIGNAL (clicked()),this, SLOT (menosBoton()));

    nP = new QPushButton("No paginado" ,this);
    nP->setGeometry(QRect( QPoint(1020, 970), QSize(120, 20) ));
    nP->setStyleSheet("background-color: dark-grey;color:red");
    PagSiguiente =new QPushButton("Siguiente" ,this);
    PagSiguiente->setGeometry(QRect( QPoint(500, 980), QSize(120, 20) ));
    PagSiguiente ->setStyleSheet("background-color: dark-grey;color:gray");
    PagAnterior=new QPushButton("Anterior" ,this);
    PagAnterior->setGeometry(QRect( QPoint(350, 980), QSize(120, 20) ));
    PagAnterior->setStyleSheet("background-color: dark-grey;color:gray");
    connect(PagSiguiente, SIGNAL (clicked()),this, SLOT (PagSig()));
    connect(PagAnterior, SIGNAL (clicked()),this, SLOT (PagAnt()));

    //Connect button signal to appropriate slot
    connect(nP, SIGNAL (clicked()),this, SLOT (nPBoton()));


        QPixmap bkgnd("/home/abigail/Escritorio/TecFlix/Wallpaper.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

}

void MainWindow::masBoton()
 {
    if(*zoom>1){
    *zoom = static_cast<int>((sqrt(*zoom)-1)*(sqrt(*zoom)-1));
    //Delete all existing widgets, if any.
    if ( win->layout() != nullptr )
    {
        QLayoutItem* item;
        while ( ( item = win->layout()->takeAt( 0 ) ) != nullptr )
        {
            delete item->widget();
            delete item;
        }
    }
     this->recargar();
    }

 }

void MainWindow::menosBoton()
 {
    if(*zoom>9){}
    else{
     *zoom = static_cast<int>((sqrt(*zoom)+1)*(sqrt(*zoom)+1));
    //Delete all existing widgets, if any.
    if ( win->layout() != nullptr )
    {
        QLayoutItem* item;
        while ( ( item = win->layout()->takeAt( 0 ) ) != nullptr )
        {
            delete item->widget();
            delete item;
        }
    }
     this->recargar();
    }
 }
void MainWindow::nPBoton()

 {
       QString s = "http://www.imdb.com/title/tt1345836/?ref_=fn_tt_tt_1";
      QString h = s.insert(4,"s");

        Don.makeRequest(h);
        cout <<endl;
         cout <<"AAAA" << h.toStdString() << "AAAA";
}

void MainWindow::dataInDaHouse(QByteArray data)
{
    QString dataString;
    dataString = data;

    cout << dataString.toStdString();
}

void MainWindow::CambiarPagina1()
{
    string *temp = new string( primero->text().toStdString());
    actual = atoi(temp->c_str());
    recargar();

}

void MainWindow::CambiarPagina2()
{
    string *temp = new string( segundo->text().toStdString());
    actual = atoi(temp->c_str());
    recargar();
}

void MainWindow::CambiarPagina3()
{
    string *temp = new string( tercero->text().toStdString());
    actual = atoi(temp->c_str());
    recargar();
}

void MainWindow::CambiarPagina4()
{
    string *temp = new string( cuarto->text().toStdString());
    actual = atoi(temp->c_str());
    recargar();
}

void MainWindow::CambiarPagina5()
{
    string *temp = new string( quinto->text().toStdString());
    actual = atoi(temp->c_str());
    recargar();
}

void MainWindow::MostrarInformacion(int pos)
{

    Data->ActualMatriz->get(0).print();

    if ( win != nullptr )
    {
        QLayoutItem* item;
        while ( ( item = win->layout()->takeAt( 0 ) ) != nullptr )
        {
            delete item->widget();
            delete item;
        }
    }
    layout->setGeometry(QRect( QPoint(100, 100), QSize(50, 50) ));

    ClickableLabel *label1 = new  ClickableLabel();
    label1->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(0)));
    label1->setStyleSheet("color: white");
    layout->addWidget(label1,0,1);

    ClickableLabel *label2 = new  ClickableLabel();
    label2->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(1)));
    label2->setStyleSheet("color: white");
    layout->addWidget(label2,1,1);

    ClickableLabel *label3 = new  ClickableLabel();
    label3->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(2)));
    label3->setStyleSheet("color: white");
    layout->addWidget(label3,2,1);

    ClickableLabel *label4 = new  ClickableLabel();
    label4->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(3)));
    label4->setStyleSheet("color: white");
    layout->addWidget(label4,3,1);

    ClickableLabel *label5 = new  ClickableLabel();
    label5->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(4)));
    label5->setStyleSheet("color: white");
    layout->addWidget(label5,4,1);

    ClickableLabel *label6 = new  ClickableLabel();
    label6->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(5)));
    label6->setStyleSheet("color: white");
    layout->addWidget(label6,5,1);
    ClickableLabel *label7 = new  ClickableLabel();
    label7->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(6)));
    label7->setStyleSheet("color: white");
    layout->addWidget(label7,6,1);
    ClickableLabel *label8 = new  ClickableLabel();
    label8->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(7)));
    label8->setStyleSheet("color: white");
    layout->addWidget(label8,7,1);
    ClickableLabel *label9 = new  ClickableLabel();
    label9->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(8)));
    label9->setStyleSheet("color: white");
    layout->addWidget(label9,8,1);
    ClickableLabel *label10 = new  ClickableLabel();
    label10->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(9)));
    label10->setStyleSheet("color: white");
    layout->addWidget(label10,9,1);
    ClickableLabel *label11 = new  ClickableLabel();
    label11->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(10)));
    label11->setStyleSheet("color: white");
    layout->addWidget(label11,10,1);
    ClickableLabel *label12 = new  ClickableLabel();
    label12->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(11)));
    label12->setStyleSheet("color: white");
    layout->addWidget(label12,11,1);
    ClickableLabel *label13 = new  ClickableLabel();
    label13->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(12)));
    label13->setStyleSheet("color: white");
    layout->addWidget(label13,12,1);
    ClickableLabel *label14 = new  ClickableLabel();
    label14->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(13)));
    label14->setStyleSheet("color: white");
    layout->addWidget(label14,13,1);
    ClickableLabel *label15 = new  ClickableLabel();
    label15->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(14)));
    label15->setStyleSheet("color: white");
    layout->addWidget(label15,14,1);
    ClickableLabel *label16 = new  ClickableLabel();
    label16->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(15)));
    label16->setStyleSheet("color: white");
    layout->addWidget(label16,15,1);
    ClickableLabel *label17 = new  ClickableLabel();
    label17->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(16)));
    label17->setStyleSheet("color: white");
    layout->addWidget(label17,16,1);
    ClickableLabel *label18 = new  ClickableLabel();
    label18->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(17)));
    label18->setStyleSheet("color: white");
    layout->addWidget(label18,17,1);
    ClickableLabel *label19 = new  ClickableLabel();
    label19->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(18)));
    label19->setStyleSheet("color: white");
    layout->addWidget(label19,18,1);
    ClickableLabel *label20 = new  ClickableLabel();
    label20->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(19)));
    label20->setStyleSheet("color: white");
    layout->addWidget(label20,19,1);
    ClickableLabel *label21 = new  ClickableLabel();
    label21->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(20)));
    label21->setStyleSheet("color: white");
    layout->addWidget(label21,20,1);
    ClickableLabel *label22 = new  ClickableLabel();
    label22->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(21)));
    label22->setStyleSheet("color: white");
    layout->addWidget(label22,21,1);
    ClickableLabel *label23 = new  ClickableLabel();
    label23->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(22)));
    label23->setStyleSheet("color: white");
    layout->addWidget(label23,22,1);
    ClickableLabel *label24 = new  ClickableLabel();
    label24->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(23)));
    label24->setStyleSheet("color: white");
    layout->addWidget(label24,23,1);
    ClickableLabel *label25 = new  ClickableLabel();
    label25->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(24)));
    label25->setStyleSheet("color: white");
    layout->addWidget(label25,24,1);
    ClickableLabel *label26 = new  ClickableLabel();
    label26->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(25)));
    label26->setStyleSheet("color: white");
    layout->addWidget(label26,25,1);
    ClickableLabel *label27 = new  ClickableLabel();
    label27->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(26)));
    label27->setStyleSheet("color: white");
    layout->addWidget(label27,26,1);
    ClickableLabel *label28 = new  ClickableLabel();
    label28->setText(QString::fromStdString(Data->ActualMatriz->get(pos).get(27)));
    label28->setStyleSheet("color: white");
    layout->addWidget(label28,27,1);

    ClickableLabel *label1T = new  ClickableLabel();
    label1T->setText("Color: ");
    label1T->setStyleSheet("color: white");
    layout->addWidget(label1T,0,0);

    ClickableLabel *label2T = new  ClickableLabel();
    label2T->setText("Director: ");
    label2T->setStyleSheet("color: white");
    layout->addWidget(label2T,1,0);

    ClickableLabel *label3T = new  ClickableLabel();
    label3T->setText("Críticas por reseña: ");
    label3T->setStyleSheet("color: white");
    layout->addWidget(label3T,2,0);

    ClickableLabel *label4T = new  ClickableLabel();
    label4T->setText("Duración: ");
    label4T->setStyleSheet("color: white");
    layout->addWidget(label4T,3,0);

    ClickableLabel *label5T = new  ClickableLabel();
    label5T->setText("Likes en el facebook del director: ");
    label5T->setStyleSheet("color: white");
    layout->addWidget(label5T,4,0);

    ClickableLabel *label6T = new  ClickableLabel();
    label6T->setText("Likes en el facebook del tercer actor: ");
    label6T->setStyleSheet("color: white");
    layout->addWidget(label6T,5,0);
    ClickableLabel *label7T = new  ClickableLabel();
    label7T->setText("Nombre del segundo actor: ");
    label7T->setStyleSheet("color: white");
    layout->addWidget(label7T,6,0);
    ClickableLabel *label8T = new  ClickableLabel();
    label8T->setText("Likes en el facebook del primer actor: ");
    label8T->setStyleSheet("color: white");
    layout->addWidget(label8T,7,0);
    ClickableLabel *label9T = new  ClickableLabel();
    label9T->setText("Gross: ");
    label9T->setStyleSheet("color: white");
    layout->addWidget(label9T,8,0);
    ClickableLabel *label10T = new  ClickableLabel();
    label10T->setText("Generos: ");
    label10T->setStyleSheet("color: white");
    layout->addWidget(label10T,9,0);
    ClickableLabel *label11T = new  ClickableLabel();
    label11T->setText("Nombre del primer actor: ");
    label11T->setStyleSheet("color: white");
    layout->addWidget(label11T,10,0);
    ClickableLabel *label12T = new  ClickableLabel();
    label12T->setText("Título de la película: ");
    label12T->setStyleSheet("color: white");
    layout->addWidget(label12T,11,0);
    ClickableLabel *label13T = new  ClickableLabel();
    label13T->setText("Votos de los usuarios: ");
    label13T->setStyleSheet("color: white");
    layout->addWidget(label13T,12,0);
    ClickableLabel *label14T = new  ClickableLabel();
    label14T->setText("Likes totales en facebook: ");
    label14T->setStyleSheet("color: white");
    layout->addWidget(label14T,13,0);
    ClickableLabel *label15T = new  ClickableLabel();
    label15T->setText("Nombre del tercer actor: ");
    label15T->setStyleSheet("color: white");
    layout->addWidget(label15T,14,0);
    ClickableLabel *label16T = new  ClickableLabel();
    label16T->setText("Número en el poster: ");
    label16T->setStyleSheet("color: white");
    layout->addWidget(label16T,15,0);
    ClickableLabel *label17T = new  ClickableLabel();
    label17T->setText("Palabras Clave: ");
    label17T->setStyleSheet("color: white");
    layout->addWidget(label17T,16,0);
    ClickableLabel *label18T = new  ClickableLabel();
    label18T->setText("Link de la película en imdb: ");
    label18T->setStyleSheet("color: white");
    layout->addWidget(label18T,17,0);
    ClickableLabel *label19T = new  ClickableLabel();
    label19T->setText("Usuarios por reseña: ");
    label19T->setStyleSheet("color: white");
    layout->addWidget(label19T,18,0);
    ClickableLabel *label20T = new  ClickableLabel();
    label20T->setText("Idioma: ");
    label20T->setStyleSheet("color: white");
    layout->addWidget(label20T,19,0);
    ClickableLabel *label21T = new  ClickableLabel();
    label21T->setText("País: ");
    label21T->setStyleSheet("color: white");
    layout->addWidget(label21T,20,0);
    ClickableLabel *label22T = new  ClickableLabel();
    label22T->setText("Calificación del contenido: ");
    label22T->setStyleSheet("color: white");
    layout->addWidget(label22T,21,0);
    ClickableLabel *label23T = new  ClickableLabel();
    label23T->setText("Presupuesto: ");
    label23T->setStyleSheet("color: white");
    layout->addWidget(label23T,22,0);
    ClickableLabel *label24T = new  ClickableLabel();
    label24T->setText("Año: ");
    label24T->setStyleSheet("color: white");
    layout->addWidget(label24T,23,0);
    ClickableLabel *label25T = new  ClickableLabel();
    label25T->setText("Likes en el facebook del segundo actor: ");
    label25T->setStyleSheet("color: white");
    layout->addWidget(label25T,24,0);
    ClickableLabel *label26T = new  ClickableLabel();
    label26T->setText("Calificación en imdb: ");
    label26T->setStyleSheet("color: white");
    layout->addWidget(label26T,25,0);
    ClickableLabel *label27T = new  ClickableLabel();
    label27T->setText("Relación de aspecto: ");
    label27T->setStyleSheet("color: white");
    layout->addWidget(label27T,26,0);
    ClickableLabel *label28T = new  ClickableLabel();
    label28T->setText("Likes de la película en facebook: ");
    label28T->setStyleSheet("color: white");
    layout->addWidget(label28T,27,0);
    ClickableLabel *label29 = new  ClickableLabel();
    layout->addWidget(label29,28,0);



}

void MainWindow::Siguiente()
{
    string *temp = new string( primero->text().toStdString());


    if( atoi(temp->c_str()) >= (Data->cant/9)-5){


    }else{
        int nuevo = atoi(temp->c_str())+5;
        primero->setText(QString::fromStdString(to_string(nuevo)));
        segundo->setText(QString::fromStdString(to_string(atoi(segundo->text().toStdString().c_str())+5)));
        tercero->setText(QString::fromStdString(to_string(atoi(tercero->text().toStdString().c_str())+5)));
        cuarto->setText(QString::fromStdString(to_string(atoi(cuarto->text().toStdString().c_str())+5)));
        quinto->setText(QString::fromStdString(to_string(atoi(quinto->text().toStdString().c_str())+5)));
        actual = nuevo;
        recargar();
    }

}

void MainWindow::Anterior()
{
    string *temp = new string( primero->text().toStdString());


    if( atoi(temp->c_str()) == 1){


    }else{
        int nuevo = atoi(temp->c_str())-5;
        primero->setText(QString::fromStdString(to_string(nuevo)));
        segundo->setText(QString::fromStdString(to_string(atoi(segundo->text().toStdString().c_str())-5)));
        tercero->setText(QString::fromStdString(to_string(atoi(tercero->text().toStdString().c_str())-5)));
        cuarto->setText(QString::fromStdString(to_string(atoi(cuarto->text().toStdString().c_str())-5)));
        quinto->setText(QString::fromStdString(to_string(atoi(quinto->text().toStdString().c_str())-5)));
        actual = nuevo;
        recargar();
    }

}

void MainWindow::PagSig()
{
    if (actual< Data->cantPag){
    actual++;
    recargar();
    }
}

void MainWindow::PagAnt()
{
    if (actual> 1){
    actual--;
    recargar();
    }
}

void  MainWindow::recargar(){



     Data->Leer(*zoom,actual,actual+1,actual-1);
     if ( win->layout() != nullptr )
     {
         QLayoutItem* item;
         while ( ( item = win->layout()->takeAt( 0 ) ) != nullptr )
         {
             delete item->widget();
             delete item;
         }
     }

   for (int i = 0;i<sqrt(*zoom);i++) {
       for (int j = 0;j<sqrt(*zoom); j++) {

           ClickableLabel *label1 = new  ClickableLabel();
           QPixmap pix("/home/abigail/Desktop/Proyecto1/pel.jpg");
           layout->addWidget(label1,i,j);
           int l = static_cast<int>(950/sqrt(*zoom));
           label1->setPixmap(pix.scaled(l,l,Qt::KeepAspectRatio));
           label1->pos = ((i+1)*(j+1))-1;

           connect(label1, SIGNAL (clicked(int)),this, SLOT (MostrarInformacion(int)));



       }


   }
   ClickableLabel *label1 = new  ClickableLabel();
    layout->addWidget(label1,static_cast<int>(sqrt(*zoom)),0);


}

void MainWindow::MostrarPaginas(){



    string p = to_string(actual);
    QString qstr = QString::fromStdString(p);
    primero->setText(qstr);


    p = to_string(actual+1);
    qstr = QString::fromStdString(p);
    segundo->setText(qstr);

    p = to_string(actual+2);
    qstr = QString::fromStdString(p);
    tercero->setText(qstr);

    p = to_string(actual+3);
    qstr = QString::fromStdString(p);
    cuarto->setText(qstr);

    p = to_string(actual+4);
    qstr = QString::fromStdString(p);
    quinto->setText(qstr);



}




MainWindow::~MainWindow()
{
    delete ui;
}


