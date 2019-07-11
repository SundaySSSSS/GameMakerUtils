#ifndef SPRITE_H
#define SPRITE_H

#include <QGraphicsItem>
#include "SpriteImageMng.h"

class Sprite : public QGraphicsItem
{
public:
    typedef enum _MoveCmd
    {
        DO_NOTHING = 0,
        UP,             //向上移动
        DOWN,           //向下移动
        LEFT,           //向左移动
        RIGHT,          //向右移动
        TURN_UP,        //转向上方（不移动）
        TURN_DOWN,      //转向下方（不移动）
        TURN_LEFT,      //转向左方（不移动）
        TURN_RIGHT,     //转向右方（不移动）
    }
    MoveCmd;

    Sprite();
    ~Sprite();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    //设置角色行走图
    void setImage(const QImage& image);
    //发送移动命令
    void setMoveCommand(MoveCmd cmd);

private:
    MoveCmd m_curCmd;   //当前移动命令
    SpriteImageMng* m_pImageMng;  //图片管理器
    QImage m_curImg;    //当前要显示的图片
    QRect m_curRect;    //当前外边框

};

#endif // SPRITE_H
