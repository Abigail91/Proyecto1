#include "clickablelabel.h"
/**
 * @brief Clase que gestiona los carteles de las peliculas.
 */
ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}
/**
 * @brief Emite la señal clicked al ser presionado.
 */
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked(this->pos);
}
