#include "ItemSpawnWidget.h"
#include "ItemSpawnDelegate.h"
#include "GameDefinitions.h"
#include <QBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>

ItemSpawnWidget::ItemSpawnWidget(QSize cellSize, QWidget* parent)
    :
    QWidget{ parent }
{
    _cell = new QTableWidget(1, 1);
    _cell->setItemDelegate(new ItemSpawnDelegate);
    _cell->horizontalHeader()->setDefaultSectionSize(cellSize.width());
    _cell->verticalHeader()->setDefaultSectionSize(cellSize.height());
    _cell->horizontalHeader()->hide();
    _cell->verticalHeader()->hide();
    _cell->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _cell->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _cell->setFixedSize({ cellSize.width(), cellSize.height() });
    _cell->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _cell->setFocusPolicy(Qt::NoFocus);
    _cell->setSelectionMode(QAbstractItemView::SingleSelection);
    _cell->setDragEnabled(true);
    _cell->setAcceptDrops(true);
    _cell->setDropIndicatorShown(true);
    _cell->setDragDropMode(QAbstractItemView::DragOnly);

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_cell);

    auto image = QImage(QString(":/images/apple.png"));
    auto item = new QTableWidgetItem;
    item->setData(static_cast<int>(Role::Icon), image);
    item->setData(static_cast<int>(Role::Number), 1);
    item->setData(static_cast<int>(Role::Type), static_cast<int>(ItemType::Apple));
    item->setData(static_cast<int>(Role::FromInventory), false);
    setItem(item);
}

void ItemSpawnWidget::setItem(QTableWidgetItem* item)
{
    _cell->setItem(0, 0, item);
}
