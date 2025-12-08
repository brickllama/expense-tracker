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
        bool connect();
        bool add(const Core::Expense& expense);
        std::optional<Core::Expense> get(const int& id);
        bool remove(const Core::Expense& expense);
        bool edit(const Core::Expense& expense);
    };
}
