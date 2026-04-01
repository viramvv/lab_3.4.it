cmake_minimum_required(VERSION 3.20)
project(CircularListProject)

set(CMAKE_CXX_STANDARD 17)

# Додаємо бібліотеку з логікою списку, щоб її могли використовувати і main, і тести
add_library(CircularListLib CircularList.cpp CircularList.h)

# Основна програма
add_executable(MainApp main.cpp)
target_link_libraries(MainApp CircularListLib)

# --- Налаштування Google Test ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: запобігання конфлікту з run-time бібліотеками
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Створення тестового файлу
add_executable(UnitTest UnitTest.cpp)
target_link_libraries(UnitTest CircularListLib gtest_main) # gtest_main додає функцію main автоматично

include(GoogleTest)
gtest_discover_tests(UnitTest)