#pragma once
#include "GameDefinitions.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class InventoryDataBase
{
public:
    InventoryDataBase();
    ~InventoryDataBase();

    void clearDB();
    void insertCell(int cell, ItemType type, int count);
    void eraseCell(int cell);

private:
    QSqlDatabase    _db;
    QSqlQuery*      _query{ nullptr };
};
