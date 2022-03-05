#pragma once
#include <QItemDelegate>

class ItemSpawnDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ItemSpawnDelegate(QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};
