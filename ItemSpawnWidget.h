#pragma once
#include <QWidget>

class QTableWidget;
class QTableWidgetItem;

class ItemSpawnWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemSpawnWidget(QSize cellSize, QWidget* parent = nullptr);

    void setItem(QTableWidgetItem* item);

private:
    QTableWidget*       _cell{ nullptr };
};
