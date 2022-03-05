QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameInventory
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        MainGUI.cpp \
        MainMenuWidget.cpp \
        GameWidget.cpp \
        InventoryWidget.cpp \
        ItemSpawnWidget.cpp \
        item.cpp \
        ItemSpawnDelegate.cpp \
        InventoryDelegate.cpp \
        Inventory.cpp \
        InventoryDataBase.cpp

HEADERS += \
        MainGUI.h \
        MainMenuWidget.h \
        GameWidget.h \
        InventoryWidget.h \
        ItemSpawnWidget.h \
        Item.h \
        GameDefinitions.h \
        ItemSpawnDelegate.h \
        InventoryDelegate.h \
        Inventory.h \
        InventoryDataBase.h

RESOURCES += \
        resources.qrc
