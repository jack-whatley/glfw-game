cmake_minimum_required (VERSION 3.27)
project (glfwGlad)

file (GLOB_RECURSE GLAD_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_library (glfwGlad "${GLAD_SOURCES}")

target_include_directories (glfwGlad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")