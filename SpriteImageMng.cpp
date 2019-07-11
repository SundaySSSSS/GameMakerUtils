#include "SpriteImageMng.h"

SpriteImageMng::SpriteImageMng(const QImage& image)
{
    m_image = image;
    //根据图片要求计算每片的大小
    int h = image.height() / 4;
    int w = image.width() / 3;

    m_mapPieceToImage.insert(DOWN1, m_image.copy(0, 0, w, h));
    m_mapPieceToImage.insert(DOWN2, m_image.copy(w, 0, w, h));
    m_mapPieceToImage.insert(DOWN3, m_image.copy(2 * w, 0, w, h));

    m_mapPieceToImage.insert(RIGHT1, m_image.copy(0, h, w, h));
    m_mapPieceToImage.insert(RIGHT2, m_image.copy(w, h, w, h));
    m_mapPieceToImage.insert(RIGHT3, m_image.copy(2 * w, h, w, h));

    m_mapPieceToImage.insert(LEFT1, m_image.copy(0, 2 * h, w, h));
    m_mapPieceToImage.insert(LEFT2, m_image.copy(w, 2 * h, w, h));
    m_mapPieceToImage.insert(LEFT3, m_image.copy(2 * w, 2 * h, w, h));

    m_mapPieceToImage.insert(UP1, m_image.copy(0, 0, w, h));
    m_mapPieceToImage.insert(UP2, m_image.copy(w, 0, w, h));
    m_mapPieceToImage.insert(UP3, m_image.copy(2 * w, 0, w, h));
}

QImage SpriteImageMng::getImage(SpriteImageMng::ImgPiece imgPieceIndex)
{
    return m_mapPieceToImage.value(imgPieceIndex);
}
