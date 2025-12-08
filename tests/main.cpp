#include <gtest/gtest.h>
#include <QtCore/QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication application(argc, argv);

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
