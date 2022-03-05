#pragma once
#include <QObject>

enum class ItemType
{
    Unknown = 0,
    Apple
};

enum class Role : int
{
    Icon = Qt::UserRole,
    Number,
    Type,
    FromInventory,
    PrevRow,
    PrevColumn
};
