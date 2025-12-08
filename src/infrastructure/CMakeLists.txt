find_package(Qt6 REQUIRED COMPONENTS Sql)

add_library(infrastructure)

target_sources(infrastructure
    PUBLIC FILE_SET
        CXX_MODULES FILES
            expense_database.cppm
    PRIVATE
        expense_database.cpp
)

target_include_directories(infrastructure
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include/infrastructure
)

target_link_libraries(infrastructure
    PUBLIC
        application
    PRIVATE
        Qt6::Sql
)
