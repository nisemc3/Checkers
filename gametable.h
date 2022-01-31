#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QObject>
#include <QGraphicsScene>

class GameTable : public QGraphicsScene
{
        Q_OBJECT
    public:
        explicit GameTable(QObject *parent = nullptr);

    signals:

};

#endif // GAMETABLE_H
