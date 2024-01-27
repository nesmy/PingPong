cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(PingPong)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES src/*.cpp )

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(vendor/raylib)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy_directory 
	"${CMAKE_CURRENT_SOURCE_DIR}/assets"
     "${CMAKE_CURRENT_SOURCE_DIR}/build/assets" 
  COMMENT "Copying to output directory")

target_include_directories(${PROJECT_NAME}
  PUBLIC include
  PUBLIC vendor/raylib/src
  )

target_link_libraries(${PROJECT_NAME}
  raylib
  )
