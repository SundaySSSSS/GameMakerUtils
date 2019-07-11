#include "Sprite.h"

#include <QGraphicsScene>
#include <QPainter>

Sprite::Sprite()
{
    m_curCmd = DO_NOTHING;
    m_pImageMng = nullptr;
    m_curRect = QRect(-16, -16, 32, 32);
}

Sprite::~Sprite()
{
    if (nullptr != m_pImageMng)
    {
        delete m_pImageMng;
        m_pImageMng = nullptr;
    }
}

QRectF Sprite::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!m_curImg.isNull())
    {
        painter->drawImage(m_curRect, m_curImg);
    }
//    // Body
//    QColor color(255, 0, 0);
//    painter->setBrush(color);
//    painter->drawEllipse(-10, -20, 20, 40);

//    // Eyes
//    painter->setBrush(Qt::white);
//    painter->drawEllipse(-10, -17, 8, 8);
//    painter->drawEllipse(2, -17, 8, 8);

//    // Nose
//    painter->setBrush(Qt::black);
//    painter->drawEllipse(QRectF(-2, -22, 4, 4));

//    // Pupils
//    painter->drawEllipse(QRectF(-8.0, -17, 4, 4));
//    painter->drawEllipse(QRectF(4.0, -17, 4, 4));

//    // Ears
//    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
//    painter->drawEllipse(-17, -12, 16, 16);
//    painter->drawEllipse(1, -12, 16, 16);

//    // Tail
//    QPainterPath path(QPointF(0, 20));
//    path.cubicTo(-5, 22, -5, 22, 0, 25);
//    path.cubicTo(5, 27, 5, 32, 0, 30);
//    path.cubicTo(-5, 32, -5, 42, 0, 35);
//    painter->setBrush(Qt::NoBrush);
//    painter->drawPath(path);
}

void Sprite::setImage(const QImage& image)
{
    if (nullptr != m_pImageMng)
    {
        delete m_pImageMng;
    }
    m_pImageMng = new SpriteImageMng(image);
    m_curImg = m_pImageMng->getImage(SpriteImageMng::UP1);
}

void Sprite::setMoveCommand(Sprite::MoveCmd cmd)
{
    switch(cmd)
    {
    case TURN_UP:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::UP1);
        break;
    case TURN_DOWN:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::DOWN1);
        break;
    default:
        break;
    }
}
