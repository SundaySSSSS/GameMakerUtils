#ifndef SPRITEIMAGEMNG_H
#define SPRITEIMAGEMNG_H

#include <QImage>
#include <QMap>

class SpriteImageMng
{
public:
    typedef enum _ImgPiece
    {
        UP1,
        UP2,
        UP3,
        DOWN1,
        DOWN2,
        DOWN3,
        LEFT1,
        LEFT2,
        LEFT3,
        RIGHT1,
        RIGHT2,
        RIGHT3,
    }
    ImgPiece;
    typedef enum _ImgType
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
    }
    ImgType;

    SpriteImageMng(const QImage& image);
    //直接获取指定图片
    QImage getImage(ImgPiece imgPieceIndex);
    //获取某一行为的下一张图片
    QImage getNextImage(ImgType type);
private:
    QImage m_image;
    QMap<ImgPiece, QImage> m_mapPieceToImage;
};

#endif // SPRITEIMAGEMNG_H
