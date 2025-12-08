add_library(infrastructure)

target_sources(infrastructure
    PUBLIC FILE_SET
        CXX_MODULES FILES
            expense_database.cppm
    PRIVATE
        expense_database.cpp
)

target_link_libraries(infrastructure
    PUBLIC
        application
)
