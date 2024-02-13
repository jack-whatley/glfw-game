cmake_minimum_required (VERSION 3.27)

set (CXX_STANDARD 20)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (glfw-game)

file (GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

# custom command for copying all shaders to out dir
file (GLOB SHADER_FILES "${CMAKE_SOURCE_DIR}/resources/shaders/*.*")

add_custom_target (copy_assets
	COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)

find_package (glfw3 CONFIG REQUIRED)
add_subdirectory ("thirdParty/glad")

add_executable (glfw-game "${GAME_SOURCES}")
add_dependencies (glfw-game copy_assets)

target_include_directories (glfw-game PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories (glfw-game PRIVATE "${CMAKE_SOURCE_DIR}/thirdParty/stb")

target_link_libraries (glfw-game PRIVATE glfw)
target_link_libraries (glfw-game PRIVATE glfwGlad)