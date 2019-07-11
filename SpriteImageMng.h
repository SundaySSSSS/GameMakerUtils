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
    SpriteImageMng(const QImage& image);

    QImage getImage(ImgPiece imgPieceIndex);
private:
    QImage m_image;
    QMap<ImgPiece, QImage> m_mapPieceToImage;
};

#endif // SPRITEIMAGEMNG_H
