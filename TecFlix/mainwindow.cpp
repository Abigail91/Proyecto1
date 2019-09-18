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
    nP->setGeometry(QRect( QPoint(1015, 920), QSize(120, 50) ));
    nP->setStyleSheet("background-color: dark-grey;color:red");

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

void  MainWindow::recargar(){
    int actual = 2;
    int siguiente = 3;
    int anterior = 1;

     Archivo Data;
     Data.Leer(*zoom,actual,siguiente,anterior);

   for (int i = 0;i<sqrt(*zoom);i++) {
       for (int j = 0;j<sqrt(*zoom); j++) {

           QLabel *label1 = new QLabel();
           QPixmap pix("/home/abigail/Desktop/Proyecto1/pel.jpg");
           layout->addWidget(label1,i,j);
           int l = static_cast<int>(950/sqrt(*zoom));
           label1->setPixmap(pix.scaled(l,l,Qt::KeepAspectRatio));
       }

   };

}





MainWindow::~MainWindow()
{
    delete ui;
}


