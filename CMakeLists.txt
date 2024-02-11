cmake_minimum_required (VERSION 3.27)

set (CXX_STANDARD 20)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (glfw-game)

find_package (glfw3 CONFIG REQUIRED)

add_executable (glfw-game main.cpp)

target_link_libraries (glfw-game PRIVATE glfw)