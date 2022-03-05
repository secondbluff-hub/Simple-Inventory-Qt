#include "Inventory.h"

Inventory::Inventory(int rows, int columns)
    :
     _size{ rows * columns },
     _cells{ rows, QVector<Cell>(columns) }
{
}

void Inventory::insertItem(int row, int column, const Item& item, int count)
{
    if(row >=0 && column >= 0 && row < _cells.size() && column < _cells.front().size())
    {
        _cells[row][column].item = item;
        _cells[row][column].count += count;
    }
}

void Inventory::eraseItem(int row, int column)
{
    if(row >=0 && column >= 0 && row < _cells.size() && column < _cells.front().size())
    {
        _cells[row][column].item = {};
        _cells[row][column].count = 0;
    }
}

Cell Inventory::cell(int row, int column)
{
    if(row >=0 && column >= 0 && row < _cells.size() && column < _cells.front().size())
    {
        return _cells[row][column];
    }
    else
    {
        return {};
    }
}

void Inventory::clickedItem(int row, int column)
{
    if(row >=0 && column >= 0 && row < _cells.size() && column < _cells.front().size())
    {
        --_cells[row][column].count;
        _cells[row][column].item.clicked();
    }
}

void Inventory::clear()
{
    for(int i = 0; i < _cells.size(); ++i)
    {
        for(int j = 0; j < _cells[i].size(); ++j)
        {
            _cells[i][j].item.clear();
            _cells[i][j].count = 0;
        }
    }
}
