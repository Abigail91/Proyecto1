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




};

#endif // MAINWINDOW_H
