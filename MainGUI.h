#pragma once
#include <QDialog>

class MainMenuWidget;
class QPushButton;
class GameWidget;

class MainGUI : public QDialog
{
    Q_OBJECT

public:
    MainGUI(QWidget* parent = nullptr);

private slots:
    void openMainMenu(); // Выход в главное меню и блокировка игрового виджета
    void runNewGame(); // Инициация новой игры

private:
    MainMenuWidget* _mainMenuWidget{ nullptr };
    QPushButton*    _openMainMenuBtn{ nullptr };
    GameWidget*     _gameWidget{ nullptr };
};
