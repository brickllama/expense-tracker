add_library(core)

target_sources(core
    PUBLIC FILE_SET
        CXX_MODULES FILES
            database.cppm
            expense.cppm
            expense_category.cppm
)
