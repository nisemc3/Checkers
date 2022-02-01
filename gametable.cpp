#include "gametable.h"

GameTable::GameTable(quint8 size, QObject *parent)
    : QGraphicsScene{parent}, m_squareSize(size)
{


    //m_bForm.setLayout(&m_bGridLayout);
    //this->addItem(&m_bForm);
}

void GameTable::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->setRenderHint(QPainter::Antialiasing);
    int tempRow = 0;
    int tempColumn = 0;
    QString letter = "ABCDEFGH";
    QString number = "12345678";
    QFont font = painter->font();
    font.setPointSize(this->sceneRect().width() / m_squareSize / 3);
    for (int row = 0; row < m_squareSize; row++)
    {
        for(int column = 0; column < m_squareSize; column++)
            {
                if (!row && (column != 0))
                {
                    painter->setBrush(Qt::black);
                    painter->setFont(font);
                    painter->drawText(tempRow,
                                      tempColumn,
                                      this->sceneRect().width() / m_squareSize,
                                      this->sceneRect().width() / m_squareSize,
                                      Qt::AlignCenter,
                                      letter.at(column-1));
                }
                else if (!column && (row != 0))
                {
                    painter->setBrush(Qt::black);
                    painter->setFont(font);
                    painter->drawText(tempRow,
                                      tempColumn,
                                      this->sceneRect().width() / m_squareSize,
                                      this->sceneRect().width() / m_squareSize,
                                      Qt::AlignCenter,
                                      number.at(row-1));
                }
                else if ((row + column) & 1)
                {
                    painter->setBrush(Qt::gray);
                    painter->drawRect(tempRow,
                                      tempColumn,
                                      this->sceneRect().width() / m_squareSize,
                                      this->sceneRect().width() / m_squareSize);
                }
                else if (row != 0)
                {
                    painter->setBrush(Qt::black);
                    painter->drawRect(tempRow,
                                      tempColumn,
                                      this->sceneRect().width() / m_squareSize,
                                      this->sceneRect().width() / m_squareSize);
                }
                tempRow += this->sceneRect().width() / m_squareSize;
            }
        tempRow = 0;
        tempColumn += this->sceneRect().width() / m_squareSize;
    }


    Q_UNUSED(rect);
}
