#include "MainGUI.h"
#include "MainMenuWidget.h"
#include "GameWidget.h"

#include <QBoxLayout>
#include <QPushButton>

MainGUI::MainGUI(QWidget* parent)
    :
    QDialog{ parent }
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    _mainMenuWidget = new MainMenuWidget;
    connect(_mainMenuWidget, &MainMenuWidget::exit, this, &QDialog::close);

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(_mainMenuWidget);
    mainLayout->addStretch();

    _openMainMenuBtn = new QPushButton(QStringLiteral("В главное меню"));
    connect(_openMainMenuBtn, &QPushButton::clicked, this, &MainGUI::openMainMenu);
    connect(_mainMenuWidget, &MainMenuWidget::startNewGame, this, &MainGUI::runNewGame);
    _openMainMenuBtn->setEnabled(false);

    _gameWidget = new GameWidget;
    _gameWidget->setEnabled(false);

    auto gameLayout = new QVBoxLayout;
    gameLayout->addWidget(_openMainMenuBtn);
    gameLayout->addStretch();
    gameLayout->addWidget(_gameWidget);
    gameLayout->addStretch();

    mainLayout->addLayout(gameLayout);
    mainLayout->addStretch();
}

void MainGUI::openMainMenu()
{
    _mainMenuWidget->collapseWidget();
    _openMainMenuBtn->setEnabled(false);
    _gameWidget->setEnabled(false);
}

void MainGUI::runNewGame()
{
    _openMainMenuBtn->setEnabled(true);
    _gameWidget->startNewGame();
    _gameWidget->setEnabled(true);
}
