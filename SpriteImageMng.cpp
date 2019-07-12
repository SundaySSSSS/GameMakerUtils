#include "SpriteImageMng.h"
#include <QDebug>

SpriteImageMng::SpriteImageMng(const QImage& image)
{
    m_image = image;
    //根据图片要求计算每片的大小
    int h = image.height() / 4;
    int w = image.width() / 3;

    m_mapPieceToImage.insert(DOWN1, m_image.copy(0, 0, w, h));
    m_mapPieceToImage.insert(DOWN2, m_image.copy(w, 0, w, h));
    m_mapPieceToImage.insert(DOWN3, m_image.copy(2 * w, 0, w, h));

    m_mapPieceToImage.insert(LEFT1, m_image.copy(0, h, w, h));
    m_mapPieceToImage.insert(LEFT2, m_image.copy(w, h, w, h));
    m_mapPieceToImage.insert(LEFT3, m_image.copy(2 * w, h, w, h));

    m_mapPieceToImage.insert(RIGHT1, m_image.copy(0, 2 * h, w, h));
    m_mapPieceToImage.insert(RIGHT2, m_image.copy(w, 2 * h, w, h));
    m_mapPieceToImage.insert(RIGHT3, m_image.copy(2 * w, 2 * h, w, h));

    m_mapPieceToImage.insert(UP1, m_image.copy(0, 3 * h, w, h));
    m_mapPieceToImage.insert(UP2, m_image.copy(w, 3 * h, w, h));
    m_mapPieceToImage.insert(UP3, m_image.copy(2 * w, 3 * h, w, h));
}

QImage SpriteImageMng::getImage(SpriteImageMng::ImgPiece imgPieceIndex)
{
    return m_mapPieceToImage.value(imgPieceIndex);
}

QImage SpriteImageMng::getNextImage(SpriteImageMng::ImgType type)
{
    QImage image;
    static int type_index[4] = {0, 0, 0, 0};
    switch(type)
    {
    case ImgType::UP:
        image = getImage(static_cast<ImgPiece>(ImgPiece::UP1 + type_index[type]));
        break;
    case ImgType::DOWN:
        image = getImage(static_cast<ImgPiece>(ImgPiece::DOWN1 + type_index[type]));
        break;
    case ImgType::LEFT:
        image = getImage(static_cast<ImgPiece>(ImgPiece::LEFT1 + type_index[type]));
        break;
    case ImgType::RIGHT:
    default:
        image = getImage(static_cast<ImgPiece>(ImgPiece::RIGHT1 + type_index[type]));
        break;
    }
    type_index[type] = (++type_index[type]) % 3;
    return image;
}
