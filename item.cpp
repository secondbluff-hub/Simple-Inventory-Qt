#include "Item.h"
#include <QSound>

Item::Item()
{
}

Item::Item(ItemType type, QIcon icon)
    :
    _type{ type },
    _picture{ icon }
{
}

Item::Item(const Item &item)
{
    _type = item.type();
    _picture = item.icon();
}

Item& Item::operator=(const Item& item)
{
    _type = item.type();
    _picture = item.icon();
    return *this;
}

ItemType Item::type() const
{
    return _type;
}

void Item::setType(ItemType type)
{
    _type = type;
}

QIcon Item::icon() const
{
    return _picture;
}

void Item::setIcon(QIcon icon)
{
    _picture = icon;
}

void Item::clicked() const
{
    switch(_type)
    {
        case ItemType::Apple:
            QSound::play(":/sounds/eatApple.wav");
            break;

        default:
            break;
    }
}

void Item::clear()
{
    _type = ItemType::Unknown;
    _picture = QIcon();
}
