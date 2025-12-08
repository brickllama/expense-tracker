#include <gtest/gtest.h>
#include <QtCore/QDateTime>
import Core.Expense;
import Core.ExpenseCategory;
import Infrastructure.ExpenseDatabase;

TEST(Infrastructure_ExpenseDatabase, connect_SHOULD_return_true)
{
    Infrastructure::ExpenseDatabase edb;
    ASSERT_TRUE(edb.connect());
}

TEST(Infrastructure_ExpenseDatabase, insert_should_return_true)
{
    Infrastructure::ExpenseDatabase edb;
    auto category = Core::ExpenseCategory::Other;
    auto expense = Core::Expense
    {
        std::nullopt,
        "Galai",
        category,
        "Anniversary Dinner",
        189.32,
        QDateTime::currentDateTime().toString().toStdString()
    };
    ASSERT_TRUE(edb.insert(expense));
}