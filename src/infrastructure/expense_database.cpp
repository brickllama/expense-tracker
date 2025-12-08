module; // Global Module Fragment

#include <iostream>
#include <print>

#include <optional>
#include <QtSql/QSqlDatabase>

module Infrastructure.ExpenseDatabase; // Implementation Unit
import Core.Expense;
import Core.IDatabase;

namespace Infrastructure
{
    bool ExpenseDatabase::connect()
    {
        QSqlDatabase db;
        if (db.contains("expense"))
            db.database("expense");
        else
            db.addDatabase("QSQLITE");

        db.setDatabaseName("ExpenseTracker.sqlite");

        std::println("DRIVER: {}, ConnectionName: {}", db.driverName().toStdString(), db.connectionName().toStdString());
        return db.open();
    }

    bool ExpenseDatabase::insert(const Core::Expense& expense)
    {
        return true;
    }

    std::optional<Core::Expense> ExpenseDatabase::select(const int& id)
    {
        return std::nullopt;
    }

    bool ExpenseDatabase::remove(const Core::Expense& expense)
    {
        return true;
    }

    bool ExpenseDatabase::update(const Core::Expense& expense)
    {
        return true;
    }
}
