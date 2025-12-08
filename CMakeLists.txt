cmake_minimum_required(VERSION 4.1.0)

project(ExpenseTracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(ExpenseTracker
    main.cpp
)

target_link_libraries(ExpenseTracker
    PRIVATE
        infrastructure
)
