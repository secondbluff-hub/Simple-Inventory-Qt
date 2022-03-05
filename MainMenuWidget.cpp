#include "MainMenuWidget.h"
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QPropertyAnimation>

MainMenuWidget::MainMenuWidget(const int animationDuration, QWidget* parent)
    :
    QWidget{ parent },
    _animationDuration{ animationDuration },
    _toggleVar{ false }
{
    _contentArea = new QScrollArea;
    _contentArea->setStyleSheet("QScrollArea { border: none; }");
    _contentArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    _contentArea->setMaximumHeight(0);
    _contentArea->setMinimumHeight(0);

    _toggleAnimation = new QParallelAnimationGroup;
    _toggleAnimation->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
    _toggleAnimation->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
    _toggleAnimation->addAnimation(new QPropertyAnimation(_contentArea, "maximumHeight"));

    auto mainLayout = new QGridLayout(this);
    mainLayout->setVerticalSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(_contentArea, 0, 0, 1, 3);

    auto title = new QLabel(QStringLiteral("Главное меню"));
    auto btnLayout = new QHBoxLayout;
    btnLayout->addStretch();

    auto newGameBtn = new QPushButton(QStringLiteral("Новая игра"));
    connect(newGameBtn, &QPushButton::clicked, this, [this]()
    {
        collapseWidget();
        emit startNewGame();
    });
    btnLayout->addWidget(newGameBtn);
    btnLayout->addStretch();

    auto exitBtn = new QPushButton(QStringLiteral("Выход"));
    connect(exitBtn, &QPushButton::clicked, this, &MainMenuWidget::exit);
    btnLayout->addWidget(exitBtn);
    btnLayout->addStretch();

    auto menuLayout = new QVBoxLayout;
    menuLayout->addWidget(title);
    menuLayout->addLayout(btnLayout);
    menuLayout->addStretch();

    _contentArea->setLayout(menuLayout);
    const auto collapsedHeight = sizeHint().height() - _contentArea->maximumHeight();
    auto contentHeight = menuLayout->sizeHint().height();
    for (int i = 0; i < _toggleAnimation->animationCount() - 1; ++i)
    {
        auto spoilerAnimation = static_cast<QPropertyAnimation*>(_toggleAnimation->animationAt(i));
        spoilerAnimation->setDuration(animationDuration);
        spoilerAnimation->setStartValue(collapsedHeight);
        spoilerAnimation->setEndValue(collapsedHeight + contentHeight);
    }
    auto contentAnimation = static_cast<QPropertyAnimation*>(_toggleAnimation->animationAt(_toggleAnimation->animationCount() - 1));
    contentAnimation->setDuration(animationDuration);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentHeight);

    collapseWidget();
}

void MainMenuWidget::collapseWidget()
{
    _toggleAnimation->setDirection(_toggleVar ? QAbstractAnimation::Backward : QAbstractAnimation::Forward);
    _toggleAnimation->start();
    _toggleVar = _toggleVar ? false : true;
}
