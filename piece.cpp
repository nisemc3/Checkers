#include "piece.h"

Piece::Piece(bool enemyPiece, QRect rect)
    : QGraphicsObject(), m_rect(rect), m_enemyPiece(enemyPiece)
{
    this->setAcceptHoverEvents(true);
    this->setAcceptedMouseButtons(Qt::MouseButton::LeftButton);
    m_brush.setStyle(Qt::Dense5Pattern);
    if (m_enemyPiece)
        m_brush.setColor(Qt::red);
    else
        m_brush.setColor(Qt::green);
}

QRectF Piece::boundingRect() const
{
    return m_rect;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(m_brush);
    painter->drawEllipse(m_rect);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Piece::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_brush.setStyle(Qt::SolidPattern);
    Q_UNUSED(event);
}

void Piece::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    m_brush.setStyle(Qt::Dense5Pattern);
    Q_UNUSED(event);
}
