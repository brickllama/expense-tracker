module; // Global Module Fragment

#include <optional>

export module Core.IDatabase; // Interface Unit

import Core.Expense;

namespace Core
{
    export class IDatabase
    {
    public:
        virtual ~IDatabase() = default;
        virtual bool connect() = 0;
        virtual bool add(const Expense& expense) = 0;
        virtual std::optional<Expense> get(const int& id) = 0;
        virtual bool remove(const Expense& expense) = 0;
        virtual bool edit(const Expense& expense) = 0;
    };
}
