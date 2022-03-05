#include "InventoryDataBase.h"

InventoryDataBase::InventoryDataBase()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("./inventoryDB.db");
    auto k0 = _db.open();

    _query = new QSqlQuery(_db);
    _query->exec("CREATE TABLE Item("
                 "Id INT,"
                 "Type TEXT,"
                 "Picture TEXT,"
                 "PRIMARY KEY (Id));");

    _query->exec("CREATE TABLE Cell("
                 "Id INT,"
                 "ItemId INT,"
                 "Count INT,"
                 "PRIMARY KEY (Id),"
                 "FOREIGN KEY (ItemId) REFERENCES Item(Id));");

    _query->exec("CREATE TABLE Inventory("
                 "Id INT,"
                 "Size INT,"
                 "Cell1 INT,"
                 "Cell2 INT,"
                 "Cell3 INT,"
                 "Cell4 INT,"
                 "Cell5 INT,"
                 "Cell6 INT,"
                 "Cell7 INT,"
                 "Cell8 INT,"
                 "Cell9 INT,"
                 "PRIMARY KEY (Id),"
                 "FOREIGN KEY (Cell1) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell2) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell3) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell4) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell5) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell6) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell7) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell8) REFERENCES Cell(Id),"
                 "FOREIGN KEY (Cell9) REFERENCES Cell(Id));");

     _query->exec("INSERT INTO Inventory(Id, Size, Cell1, Cell2, Cell3, Cell4, Cell5, Cell6, Cell7, Cell8, Cell9)"
      "VALUES(0, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8);");

     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(0, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(1, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(2, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(3, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(4, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(5, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(6, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(7, 0, 0);");
     _query->exec("INSERT INTO Cell(Id, ItemId, Count)"
      "VALUES(8, 0, 0);");

     _query->exec("INSERT INTO Item(Id, Type, Picture)"
      "VALUES(0, 'Unknown', '');");
     _query->exec("INSERT INTO Item(Id, Type, Picture)"
                 "VALUES(1, 'Apple', ':/images/apple.png');");
}

InventoryDataBase::~InventoryDataBase()
{
    _db.close();
}

void InventoryDataBase::clearDB()
{
    for(int i = 0; i < 9; ++i)
    {
        eraseCell(i);
    }
}

void InventoryDataBase::insertCell(int cell, ItemType type, int count)
{
    switch(type)
    {
        case ItemType::Apple:
            _query->exec(QStringLiteral("UPDATE Cell SET ItemId = 1, Count = %1 WHERE Id = %2").arg(count).arg(cell));
            break;

        default:
            break;
    }
}

void InventoryDataBase::eraseCell(int cell)
{
    _query->exec(QStringLiteral("UPDATE Cell SET ItemId = 0, Count = 0 WHERE Id = %1").arg(cell));
}
