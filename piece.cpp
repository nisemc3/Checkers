#include "piece.h"

Piece::Piece(bool enemyPiece, QRectF rectF)
    : QGraphicsObject(), m_rectF(rectF), m_enemyPiece(enemyPiece)
{
    m_brush.setStyle(Qt::Dense5Pattern);
    if (m_enemyPiece)
        m_brush.setColor(Qt::red);
    else
        m_brush.setColor(Qt::green);
}

QRectF Piece::boundingRect() const
{
    return m_rectF;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(m_brush);
    painter->drawEllipse(m_rectF);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Piece::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_brush.setStyle(Qt::SolidPattern);
    Q_UNUSED(event);
}
