cmake_minimum_required(VERSION 3.14)
project(RealNumberCompositionHierarchy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CORE_SOURCES
        Number.cpp
        RealPublic.cpp
        RealPrivate.cpp
)

add_executable(MainApp main.cpp ${CORE_SOURCES})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(UnitTest UnitTest.cpp ${CORE_SOURCES})
target_link_libraries(UnitTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTest)