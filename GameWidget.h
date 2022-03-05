#pragma once
#include <QWidget>

class InventoryWidget;
class ItemSpawnWidget;

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget* parent = nullptr);

    void startNewGame();

private:
    InventoryWidget* _invWidget{ nullptr };
    ItemSpawnWidget* _itemSpawnWidget{ nullptr };
};
