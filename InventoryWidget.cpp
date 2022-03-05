#include "InventoryWidget.h"
#include "InventoryDelegate.h"
#include "Item.h"
#include "Inventory.h"
#include "GameDefinitions.h"
#include <QBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QMouseEvent>

InventoryWidget::InventoryWidget(int rows, int columns, QSize cellSize, QWidget* parent)
    :
    QWidget{ parent }
{
    auto mainLayout = new QVBoxLayout(this);
    _inventory = new Inventory(rows, columns);
    _table = new QTableWidget(rows, columns);
    _table->setItemDelegate(new InventoryDelegate);
    _table->horizontalHeader()->setDefaultSectionSize(cellSize.width());
    _table->verticalHeader()->setDefaultSectionSize(cellSize.height());
    _table->horizontalHeader()->hide();
    _table->verticalHeader()->hide();
    _table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _table->setFixedSize({ cellSize.width() * columns, cellSize.height() * rows });
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setFocusPolicy(Qt::NoFocus);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setDragEnabled(true);
    _table->setAcceptDrops(true);
    _table->setDropIndicatorShown(true);
    _table->setDefaultDropAction(Qt::MoveAction);
    _table->setContextMenuPolicy(Qt::CustomContextMenu);
    mainLayout->addWidget(_table);
    connect(_table, &QTableWidget::customContextMenuRequested, this, &InventoryWidget::itemRightClicked);
    connect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
}

void InventoryWidget::newGame()
{
    disconnect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
    _table->clear();
    _inventory->clear();
    _inventoryDB.clearDB();
    connect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
}

void InventoryWidget::itemDropped(QTableWidgetItem* item)
{
    disconnect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
    auto row = item->row();
    auto column = item->column();
    auto type = static_cast<ItemType>(item->data(static_cast<int>(Role::Type)).toInt());
    Item it(type, item->data(static_cast<int>(Role::Icon)).value<QIcon>());
    _inventory->insertItem(row, column, it, item->data(static_cast<int>(Role::Number)).toInt());
    if(item->data(static_cast<int>(Role::FromInventory)).toBool())
    {
        auto prevRow = item->data(static_cast<int>(Role::PrevRow)).toInt();
        auto prevColumn = item->data(static_cast<int>(Role::PrevColumn)).toInt();
        _inventory->eraseItem(prevRow, prevColumn);
        _inventoryDB.eraseCell(prevRow * 3 + prevColumn);
    }
    else
    {
        item->setData(static_cast<int>(Role::FromInventory), true);
    }
    auto count = _inventory->cell(row, column).count;
    item->setData(static_cast<int>(Role::PrevRow), row);
    item->setData(static_cast<int>(Role::PrevColumn), column);
    item->setData(static_cast<int>(Role::Number), count);
    _inventoryDB.insertCell(row * 3 + column, it.type(), count);
    connect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
}

void InventoryWidget::itemRightClicked()
{
    auto item = _table->itemAt(_table->mapFromGlobal(QCursor::pos()));
    if (item)
    {
        disconnect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
        if(item->data(static_cast<int>(Role::Number)).toInt() > 0)
        {
            auto row = item->row();
            auto column = item->column();
            _inventory->clickedItem(row, column);
            item->setData(static_cast<int>(Role::Number), _inventory->cell(row, column).count);
        }
        connect(_table, &QTableWidget::itemChanged, this, &InventoryWidget::itemDropped);
    }
}
