#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include "piece.h"
#include <QVector>
#include <QGraphicsGridLayout>
#include <QRect>
#include <QDebug>

class GameTable : public QGraphicsScene
{
        Q_OBJECT
    public:
        explicit GameTable(quint8 size, QObject *parent = nullptr);



    private:
        Piece* m_piece;
        QRect m_squareRect;
        quint8 m_squareSize;

        QGraphicsGridLayout m_fGridLayout;

        QGraphicsGridLayout m_bGridLayout;
        QGraphicsWidget m_bForm;

    private:
        void drawBackground(QPainter *painter, const QRectF &rect) override;

    signals:

};

#endif // GAMETABLE_H
