#pragma once
#include "Item.h"
#include <QVector>

struct Cell
{
    Item    item;
    int     count{ 0 };
};

class Inventory
{
public:
    Inventory(int rows, int columns);

    void insertItem(int row, int column, const Item& item, int count);
    void eraseItem(int row, int column);
    void clickedItem(int row, int column);
    Cell cell(int row, int column);
    void clear();

private:
    int                     _size{ 0 };
    QVector<QVector<Cell>>  _cells;
};
