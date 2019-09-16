#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>


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

private slots:
   void masBoton();
   void menosBoton();
   void nPBoton();


private:
    Ui::MainWindow *ui;
    QPushButton*mas;
    QPushButton*menos;
     QPushButton*nP;
     QWidget *win;
      QGridLayout *layout;
      int *zoom;




};

#endif // MAINWINDOW_H
