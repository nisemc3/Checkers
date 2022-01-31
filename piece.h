#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QGraphicsObject>
#include <QGraphicsEllipseItem>
#include <QPainter>

class Piece : public QGraphicsObject, public QGraphicsEllipseItem
{
        Q_OBJECT

    private:
        QRectF m_rectF;
        QBrush m_brush;
        bool m_enemyPiece;

    public:
        explicit Piece(bool enemyPiece, QRectF rectF);

    protected:
        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    signals:

};

#endif // PIECE_H
