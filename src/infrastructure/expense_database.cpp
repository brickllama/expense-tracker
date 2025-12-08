module; // Global Module Fragment

#include <optional>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

module Infrastructure.ExpenseDatabase; // Implementation Unit
import Core.Expense;
import Core.ExpenseCategory;
import Core.IDatabase;

namespace Infrastructure
{
    bool ExpenseDatabase::connect()
    {
        QSqlDatabase db;
        if (!QSqlDatabase::contains("expense"))
        {
            db = QSqlDatabase::addDatabase("QSQLITE", "expense");
            db.setDatabaseName("ExpenseTracker.sqlite");
        }
        else
        {
            db = QSqlDatabase::database("expense");
        }
        return db.open();
    }

    bool ExpenseDatabase::table_checks()
    {
        QSqlDatabase db;
        if (!db.tables().contains("expense"))
        {
            QSqlQuery query(db);
            query.prepare(
                "CREATE TABLE IF NOT EXISTS expense ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "category INTEGER NOT NULL,"
                "description TEXT,"
                "amount REAL NOT NULL,"
                "created_at TEXT DEFAULT CURRENT_TIMESTAMP,"
                "registered INTEGER NOT NULL"
                ")"
            );
            return query.exec();
        }
        return true;
    }

    bool ExpenseDatabase::insert(const Core::Expense& expense)
    {
        if (!this->table_checks()) throw std::runtime_error("table_checks FAILED");
        QSqlDatabase db;
        QSqlQuery query(db);
        query.prepare("INSERT INTO expense (name, category, description, amount, created_at, registered)"
            "VALUES (?, ?, ?, ?, ?, ?)"
        );
        query.addBindValue(QString::fromStdString(expense.name));
        query.addBindValue(static_cast<int>(expense.category));
        query.addBindValue(QString::fromStdString(expense.description.value()));
        query.addBindValue(expense.amount);
        query.addBindValue(QString::fromStdString(expense.created_at));
        query.addBindValue(true);
        return query.exec();
    }

    std::optional<Core::Expense> ExpenseDatabase::select(const int& id)
    {
        if (!this->table_checks()) throw std::runtime_error("table_checks FAILED");
        QSqlDatabase db;
        QSqlQuery query(db);
        query.prepare("SELECT id, name, category, description, amount, created_at, registered "
            "FROM expense WHERE id = ?"
        );
        query.addBindValue(id);
        if (!query.exec()) return std::nullopt;
        if (!query.next()) return std::nullopt;
        Core::Expense expense;
        expense.id = query.value("id").toInt();
        expense.name = query.value("name").toString().toStdString();
        expense.category = static_cast<Core::ExpenseCategory>(query.value("category").toInt());
        expense.description = query.value("description").toString().toStdString();
        expense.amount = query.value("amount").toDouble();
        expense.created_at = query.value("created_at").toString().toStdString();
        return expense;
    }

    bool ExpenseDatabase::remove(const Core::Expense& expense)
    {
        if (!expense.id.has_value() || !expense.registered)
            return false;
        if (!this->table_checks()) throw std::runtime_error("table_checks FAILED");
        QSqlDatabase db;
        QSqlQuery query(db);
        query.prepare("DELETE FROM expense WHERE id = ?");
        query.addBindValue(expense.id.value());
        if (!query.exec()) return false;
        return query.numRowsAffected() > 0;
    }

    bool ExpenseDatabase::update(const Core::Expense& expense)
    {
        if (!expense.id.has_value() || !expense.registered)
            return false;
        if (!this->table_checks()) throw std::runtime_error("table_checks FAILED");
        QSqlDatabase db;
        QSqlQuery query(db);
        query.prepare("UPDATE expense SET name = ?, category = ?, "
            "description = ?, amount = ?, created_at WHERE id = ?"
        );
        query.addBindValue(QString::fromStdString(expense.name));
        query.addBindValue(static_cast<int>(expense.category));
        query.addBindValue(QString::fromStdString(expense.description.value_or("")));
        query.addBindValue(expense.amount);
        query.addBindValue(QString::fromStdString(expense.created_at));
        query.addBindValue(expense.id.value());
        if (!query.exec())
            return false;
        return query.numRowsAffected() > 0;
    }
}
