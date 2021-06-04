include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/a3460d1aeeaa43fdf137a6adefef10ba0b59fe4b.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Chapter1 Chapter1.cpp ../Chapter1/Dollar.h)
target_link_libraries(Chapter1 gtest_main)

add_executable(Chapter2 Chapter2.cpp ../Chapter2/Dollar.h)
target_link_libraries(Chapter2 gtest_main)

add_executable(Chapter3 Chapter3.cpp ../Chapter3/Dollar.h)
target_link_libraries(Chapter3 gtest_main)

add_executable(Chapter4 Chapter4.cpp ../Chapter4/Dollar.h)
target_link_libraries(Chapter4 gtest_main)

add_executable(Chapter5 Chapter5.cpp ../Chapter5/Dollar.h ../Chapter5/Franc.h)
target_link_libraries(Chapter5 gtest_main)

add_executable(Chapter6 Chapter6.cpp ../Chapter6/Dollar.h ../Chapter6/Franc.h ../Chapter6/Money.h)
target_link_libraries(Chapter6 gtest_main)

add_executable(Chapter7 Chapter7.cpp ../Chapter7/Dollar.h ../Chapter7/Franc.h ../Chapter7/Money.h)
target_link_libraries(Chapter7 gtest_main)

add_executable(Chapter8 Chapter8.cpp ../Chapter8/Dollar.h ../Chapter8/Franc.h ../Chapter8/Money.h)
target_link_libraries(Chapter8 gtest_main)

include(GoogleTest)
gtest_discover_tests(Chapter1)
gtest_discover_tests(Chapter2)
gtest_discover_tests(Chapter3)
gtest_discover_tests(Chapter4)
gtest_discover_tests(Chapter5)
gtest_discover_tests(Chapter6)
gtest_discover_tests(Chapter7)
gtest_discover_tests(Chapter8)