#include "widget.h"
#include "ui_widget.h"
#include <math.h>
#include <qmath.h>
#include <QGraphicsView>
#include <QtMath>
#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_scene.setSceneRect(-300, -300, 600, 600);

    m_scene.setItemIndexMethod(QGraphicsScene::NoIndex);

//    for (int i = 0; i < 5; ++i) {
//        Sprite *pSprite = new Sprite();
//        pSprite->setPos(qSin((i * 6.28) / 5) * 200,
//                      qCos((i * 6.28) / 5) * 200);
//        m_scene.addItem(pSprite);
//    }

    QImage image;
    if (!image.load("Actor1.png"))
    {
        qDebug() << "load image error";
        return;
    }

    m_pSprite = new Sprite();
    m_pSprite->setPos(0, 0);
    m_pSprite->setImage(image);
    m_scene.addItem(m_pSprite);

    QGraphicsView* pView = ui->graphicsView;
    pView->setScene(&m_scene);
    pView->setRenderHint(QPainter::Antialiasing);

    pView->setCacheMode(QGraphicsView::CacheBackground);
    pView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //pView->setDragMode(QGraphicsView::ScrollHandDrag);

    pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    pView->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice"));
    pView->resize(400, 300);


    QObject::connect(&m_timer, SIGNAL(timeout()), &m_scene, SLOT(advance()));
    m_timer.start(2000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if (key == Qt::Key_W)
    {
        m_pSprite->setMoveCommand(Sprite::UP);
    }
    else if (key == Qt::Key_S)
    {
        m_pSprite->setMoveCommand(Sprite::DOWN);
    }
    else if (key == Qt::Key_A)
    {
        m_pSprite->setMoveCommand(Sprite::LEFT);
    }
    else if (key == Qt::Key_D)
    {
        m_pSprite->setMoveCommand(Sprite::RIGHT);
    }
    qDebug() << "key pressed" << event->text();
}
