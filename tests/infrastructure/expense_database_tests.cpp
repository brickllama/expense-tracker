#include <gtest/gtest.h>
import Infrastructure.ExpenseDatabase;

TEST(Infrastructure_ExpenseDatabase, connect_SHOULD_return_true)
{
    Infrastructure::ExpenseDatabase edb;
    ASSERT_TRUE(edb.connect());
}