enable_testing(true)

# --- BACKEND TESTING
add_subdirectory(core)
add_subdirectory(application)

set(BACKEND_SOURCES
    ${CORE_SOURCES}
    ${APPLICATION_SOURCES}
)

find_package(GTest REQUIRED)

add_executable(BackendTests
    main.cpp
    ${BACKEND_SOURCES}
)

target_link_libraries(BackendTests
    PRIVATE
        infrastructure
        gtest
        GTest::gmock
)

target_compile_definitions(BackendTests
    PRIVATE
        UNIT_TEST
)

# These might be optional... according to the dependency chart.
# include(GoogleTest)
# gtest_discover_tests(BackendTests)
# --- END OF BACKEND TESTING