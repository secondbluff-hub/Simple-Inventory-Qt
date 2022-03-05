#include "GameWidget.h"
#include "InventoryWidget.h"
#include "ItemSpawnWidget.h"
#include <QBoxLayout>

GameWidget::GameWidget(QWidget *parent)
    :
    QWidget{ parent }
{
    auto mainLayout = new QVBoxLayout(this);
    auto hLayout = new QHBoxLayout;
    _invWidget = new InventoryWidget(3, 3, { 100, 100 });
    _itemSpawnWidget = new ItemSpawnWidget({ 100, 100 });
    hLayout->addWidget(_invWidget);
    hLayout->addStretch();
    hLayout->addWidget(_itemSpawnWidget);
    mainLayout->addLayout(hLayout);
}

void GameWidget::startNewGame()
{
    _invWidget->newGame();
}
