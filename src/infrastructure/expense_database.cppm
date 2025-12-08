module; // Global Module Fragment

#include <optional>

export module Infrastructure.ExpenseDatabase; // Interface Unit

import Core.IDatabase;
import Core.Expense;

namespace Infrastructure
{
    export class ExpenseDatabase : public Core::IDatabase
    {
    public:
        explicit ExpenseDatabase() { }
        bool connect();
        bool insert(const Core::Expense& expense);
        std::optional<Core::Expense> select(const int& id);
        bool remove(const Core::Expense& expense);
        bool update(const Core::Expense& expense);
    private:
        bool table_checks();
    };
}
