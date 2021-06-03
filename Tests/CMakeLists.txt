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

include(GoogleTest)
gtest_discover_tests(Chapter1)