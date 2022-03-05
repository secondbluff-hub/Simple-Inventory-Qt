#include "InventoryDelegate.h"
#include "GameDefinitions.h"
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QRect>
#include <QImage>

InventoryDelegate::InventoryDelegate(QObject* parent)
    :
    QItemDelegate{ parent }
{
}

void InventoryDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QItemDelegate::paint(painter, option, index);
    if(index.isValid())
    {
        painter->save();
        if(index.data(static_cast<int>(Role::Number)).toInt() > 0)
        {
            painter->drawImage(option.rect, index.data(static_cast<int>(Role::Icon)).value<QImage>());
            auto rect = option.rect;
            rect -= {2, 2, 2, 0};
            painter->drawText(rect, Qt::AlignRight | Qt::AlignBottom, index.data(static_cast<int>(Role::Number)).toString());
        }
        painter->restore();
    }
}
