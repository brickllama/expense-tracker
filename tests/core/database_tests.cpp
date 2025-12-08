#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_database.hpp"

using ::testing::Return;

TEST(Core_IDatabase, connect_SHOULD_return_true)
{
    MockDatabase mdb;
    EXPECT_CALL(mdb, connect())
        .WillOnce(Return(true));
    bool successful = mdb.connect();
    EXPECT_TRUE(successful);
}
