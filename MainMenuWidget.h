#pragma once
#include <QWidget>

class QGridLayout;
class QParallelAnimationGroup;
class QScrollArea;

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(const int animationDuration = 300, QWidget* parent = nullptr);

signals:
    void startNewGame();
    void exit();

public slots:
    void collapseWidget(); // Открытие/закрытие главного меню

private:
    QParallelAnimationGroup*    _toggleAnimation{ nullptr };
    QScrollArea*                _contentArea{ nullptr };
    int                         _animationDuration{ 300 };
    bool                        _toggleVar{ false };
};
