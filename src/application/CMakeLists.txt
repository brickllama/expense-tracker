add_library(application)

target_sources(application
    PUBLIC FILE_SET
        CXX_MODULES FILES
            expense_manager.cppm
    PRIVATE
        expense_manager.cpp
)

target_link_libraries(application
    PUBLIC
        core
)
