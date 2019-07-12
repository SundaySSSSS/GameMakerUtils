#include "Sprite.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

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
}

void Sprite::advance(int phase)
{
    //qDebug() << "sprite advance" << phase;
    if (1 == phase)
    {
        switch(m_curCmd)
        {
        case Sprite::UP:
            m_curImg = m_pImageMng->getNextImage(SpriteImageMng::UP);
            break;
        case Sprite::DOWN:
            m_curImg = m_pImageMng->getNextImage(SpriteImageMng::DOWN);
            break;
        case Sprite::LEFT:
            m_curImg = m_pImageMng->getNextImage(SpriteImageMng::LEFT);
            break;
        case Sprite::RIGHT:
            m_curImg = m_pImageMng->getNextImage(SpriteImageMng::RIGHT);
            break;
        default:
            qDebug() << "unknown cmd" << m_curCmd;
        }
        update();
    }
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
    m_curCmd = cmd;
    switch(cmd)
    {
    case TURN_UP:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::UP1);
        break;
    case TURN_DOWN:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::DOWN1);
        break;
    case TURN_LEFT:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::LEFT1);
        break;
    case TURN_RIGHT:
        m_curImg = m_pImageMng->getImage(SpriteImageMng::RIGHT1);
        break;
    case RIGHT:
        m_curImg = m_pImageMng->getNextImage(SpriteImageMng::RIGHT);
        break;
    case LEFT:
        m_curImg = m_pImageMng->getNextImage(SpriteImageMng::LEFT);
        break;
    case UP:
        m_curImg = m_pImageMng->getNextImage(SpriteImageMng::UP);
        break;
    case DOWN:
        m_curImg = m_pImageMng->getNextImage(SpriteImageMng::DOWN);
        break;
    default:
        break;
    }

    update();

}
