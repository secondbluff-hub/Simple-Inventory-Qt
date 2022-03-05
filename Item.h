#pragma once
#include <QObject>
#include <QIcon>
#include "GameDefinitions.h"

class Item
{
public:
    Item();
    Item(ItemType type, QIcon icon);
    Item(const Item& item);
    Item& operator=(const Item& item);

    ItemType type() const;
    void setType(ItemType type);

    QIcon icon() const;
    void setIcon(QIcon icon);

    void clear();
    void clicked() const;

private:
    ItemType    _type{ ItemType::Unknown };
    QIcon       _picture;
};
