find_package(GTest REQUIRED)

file(GLOB srcs CONFIGURE_DEPENDS *.cpp)
add_executable(unit-tests ${srcs})
target_compile_definitions(unit-tests PRIVATE ROOT_DIR="${CMAKE_SOURCE_DIR}")
target_link_libraries(unit-tests PRIVATE glapd-common GTest::gtest_main)
