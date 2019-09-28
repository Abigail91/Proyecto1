#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include "networkManager.h"
#include "Archivo.h"


namespace Ui {
class MainWindow;
}

/**
 * @brief Constructor por defecto
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief  Constructor por defecto
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor por defecto
     *
     */
    virtual~MainWindow();
    /**
     * @brief Recarga la informacion requerida y la muestra en pantalla.
     *
     */
    void recargar();

    /**
     * @brief Muestra los botones de paginas.
     *
     */
    void MostrarPaginas();
    Archivo *Data = new Archivo();



private slots:
   /**
    * @brief Amplia el zomm de la pantalla.
    *
    */
   void masBoton();
   /**
    * @brief Disminuye el zoom de la pantalla.
    *
    */
   void menosBoton();
   /**
    * @brief Entra en modo no paginado
    *
    */
   void nPBoton();
   /**
    * @brief 
    *
    * @param data
    */
   void dataInDaHouse(QByteArray data);
   /**
    * @brief Cambian las paginas
    *
    */
   void CambiarPagina1();
   /**
    * @brief 
    *
    */
   void CambiarPagina2();
   /**
    * @brief 
    *
    */
   void CambiarPagina3();
   /**
    * @brief 
    *
    */
   void CambiarPagina4();
   /**
    * @brief 
    *
    */
   void CambiarPagina5();
   /**
    * @brief Muestra la informacion de la pelicula.
    *
    * @param pos Posicion de la pelicula en la lista.
    */
   void MostrarInformacion(int pos);
   /**
    * @brief Pasa al siguiente bloque de botones de paginas.
    *
    */
   void Siguiente();
   /**
    * @brief Pasa al anterior bloque de botones de paginas.
    *
    */
   void Anterior();
   /**
    * @brief Pasa a la pagina siguiente.
    *
    */
   void PagSig();
   /**
    * @brief Pasa a la pagina anterior.
    *
    */
   void PagAnt();


private:
    Ui::MainWindow *ui; /**< TODO: describe */
    QPushButton*mas; /**< TODO: describe */
    QPushButton*menos; /**< TODO: describe */
     QPushButton*nP; /**< TODO: describe */
     QWidget *win; /**< TODO: describe */
      QGridLayout *layout; /**< TODO: describe */
      int *zoom; /**Cantidad de datos por pagina */
      NetworkManager Don; /**< TODO: describe */
      QPushButton * primero; /**< TODO: describe */
      QPushButton * segundo; /**< TODO: describe */
      QPushButton * tercero; /**< TODO: describe */
      QPushButton * cuarto; /**< TODO: describe */
      QPushButton * quinto; /**< TODO: describe */
      QPushButton * flecha; /**< TODO: describe */
      QPushButton * flechaAnterior; /**< TODO: describe */
      QPushButton * PagSiguiente; /**< TODO: describe */
      QPushButton * PagAnterior; /**< TODO: describe */
      int actual; /**Pagina actual*/
      int anterior; /**Pagina anterior*/
      int siguiente; /**Pagina Siguiente */
      string modo = "Paginado"; /**Modo de paginacion */







};

#endif // MAINWINDOW_H
