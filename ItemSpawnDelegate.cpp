#include "ItemSpawnDelegate.h"
#include "GameDefinitions.h"
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QRect>
#include <QImage>

ItemSpawnDelegate::ItemSpawnDelegate(QObject* parent)
    :
    QItemDelegate{ parent }
{
}

void ItemSpawnDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QItemDelegate::paint(painter, option, index);
    if(index.isValid())
    {
        painter->save();

        painter->drawImage(option.rect, index.data(static_cast<int>(Role::Icon)).value<QImage>());

        painter->restore();
    }
}
