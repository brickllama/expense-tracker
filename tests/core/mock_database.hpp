#ifndef EXPENSE_TRACKER_TESTS_CORE_MOCK_DATABASE_HPP_
#define EXPENSE_TRACKER_TESTS_CORE_MOCK_DATABASE_HPP_

#include <optional>
#include <gmock/gmock.h>
import Core.IDatabase;
import Core.Expense;

class MockDatabase : public Core::IDatabase
{
public:
    MOCK_METHOD(bool, connect, (), (override));
    MOCK_METHOD(bool, add, (const Core::Expense& expense), (override));
    MOCK_METHOD(std::optional<Core::Expense>, get, (const int& id), (override));
    MOCK_METHOD(bool, remove, (const Core::Expense& expense), (override));
    MOCK_METHOD(bool, edit, (const Core::Expense& expense), (override));
};

#endif // EXPENSE_TRACKER_TESTS_CORE_MOCK_DATABASE_HPP_