#pragma once
#include "InventoryDataBase.h"
#include <QWidget>

class QTableWidget;
class QTableWidgetItem;
class Inventory;
class QMouseEvent;

class InventoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryWidget(int rows, int columns, QSize cellSize, QWidget* parent = nullptr);

    void newGame();

public slots:
    void itemDropped(QTableWidgetItem* item);
    void itemRightClicked();

private:
    QTableWidget*       _table{ nullptr };
    Inventory*          _inventory{ nullptr };
    InventoryDataBase   _inventoryDB;
};
