#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include "networkManager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual~MainWindow();
    void recargar();
    void descargarHtml();
    void MostrarPaginas();

private slots:
   void masBoton();
   void menosBoton();
   void nPBoton();
   void dataInDaHouse(QByteArray data);


private:
    Ui::MainWindow *ui;
    QPushButton*mas;
    QPushButton*menos;
     QPushButton*nP;
     QWidget *win;
      QGridLayout *layout;
      int *zoom;
      NetworkManager Don;
      QPushButton * primero;
      QPushButton * segundo;
      QPushButton * tercero;
      QPushButton * cuarto;
      QPushButton * quinto;
      QPushButton * flecha;
      QPushButton * flechaAnterior;
      int actual;
      int anterior;
      int siguiente;






};

#endif // MAINWINDOW_H
