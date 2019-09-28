#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

/**
 * @brief Clase que gestiona los carteles de las peliculas.
 */
class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    /**
     * @brief  Constructor por defecto
     *
     * @param parent
     * @param f
     */
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    /**
     * @brief 
     *
     */
    ~ClickableLabel();
    int pos; /**Posicion en la lista de la pelicula mostrada en el label. */

signals:
    /**
     * @brief Señal al hacer click
     *
     * @param int posicion en la lista
     */
    void clicked(int);

protected:
    /**
     * @brief 
     *
     * @param event
     */
    void mousePressEvent(QMouseEvent* event);

};

#endif // CLICKABLELABEL_H
