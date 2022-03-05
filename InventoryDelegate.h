#pragma once
#include <QItemDelegate>

class InventoryDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    InventoryDelegate(QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};
