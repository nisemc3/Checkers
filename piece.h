#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QGraphicsObject>
#include <QGraphicsEllipseItem>
#include <QPainter>

class Piece : public QGraphicsObject
{
        Q_OBJECT

    private:
        QRect m_rect;
        QBrush m_brush;
        bool m_enemyPiece;

    public:
        explicit Piece(bool enemyPiece, QRect rect);

    protected:
        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    signals:

};

#endif // PIECE_H
