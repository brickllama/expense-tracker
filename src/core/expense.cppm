module; // Global Module Fragment

#include <optional>
#include <string>

export module Core.Expense; // Interface Unit

import Core.ExpenseCategory;

namespace Core
{
    export struct Expense
    {
        std::optional<int> id = std::nullopt;
        std::string name;
        ExpenseCategory category;
        std::optional<std::string> description = std::nullopt;
        double amount;
        std::string created_at;
        bool registered = false;
#ifdef UNIT_TEST
        bool operator==(const Expense& other) const
        {
            return id == other.id &&
                name == other.name &&
                category == other.category &&
                description == other.description &&
                amount == other.amount &&
                created_at == other.created_at;
        }
#endif
    };
}