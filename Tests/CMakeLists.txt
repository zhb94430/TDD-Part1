include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/a3460d1aeeaa43fdf137a6adefef10ba0b59fe4b.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Chapter1 Chapter1.cpp)
target_link_libraries(Chapter1 gtest_main)

add_executable(Chapter2 Chapter2.cpp)
target_link_libraries(Chapter2 gtest_main)

add_executable(Chapter3 Chapter3.cpp)
target_link_libraries(Chapter3 gtest_main)

add_executable(Chapter4 Chapter4.cpp)
target_link_libraries(Chapter4 gtest_main)

add_executable(Chapter5 Chapter5.cpp)
target_link_libraries(Chapter5 gtest_main)

add_executable(Chapter6 Chapter6.cpp)
target_link_libraries(Chapter6 gtest_main)

add_executable(Chapter7 Chapter7.cpp)
target_link_libraries(Chapter7 gtest_main)

add_executable(Chapter8 Chapter8.cpp)
target_link_libraries(Chapter8 gtest_main)

add_executable(Chapter9 Chapter9.cpp ../Chapter9/MoneyFactory.cpp)
target_link_libraries(Chapter9 gtest_main)

add_executable(Chapter10 Chapter10.cpp ../Chapter10/MoneyFactory.cpp)
target_link_libraries(Chapter10 gtest_main)

add_executable(Chapter11 Chapter11.cpp ../Chapter11/MoneyFactory.cpp)
target_link_libraries(Chapter11 gtest_main)

add_executable(Chapter12 Chapter12.cpp ../Chapter12/MoneyFactory.cpp)
target_link_libraries(Chapter12 gtest_main)

add_executable(Chapter13 Chapter13.cpp ../Chapter13/MoneyFactory.cpp ../Chapter13/Money.cpp)
target_link_libraries(Chapter13 gtest_main)

include(GoogleTest)
gtest_discover_tests(Chapter1)
gtest_discover_tests(Chapter2)
gtest_discover_tests(Chapter3)
gtest_discover_tests(Chapter4)
gtest_discover_tests(Chapter5)
gtest_discover_tests(Chapter6)
gtest_discover_tests(Chapter7)
gtest_discover_tests(Chapter8)
gtest_discover_tests(Chapter9)
gtest_discover_tests(Chapter10)
gtest_discover_tests(Chapter11)
gtest_discover_tests(Chapter12)
gtest_discover_tests(Chapter13)