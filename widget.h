#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "Sprite.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    QGraphicsScene m_scene;
    Sprite* m_pSprite;
};

#endif // WIDGET_H
