cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


project(PingPong)

set (HEADER_FILES
   include/enpch.h)
file(GLOB SOURCES src/Game/*.cpp vendor/stb_image/stb_image.cpp src/Engine/*.cpp vendor/imgui/*.cpp
				
		${HEADER_FILES} 
		)

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

#add_compile_definitions(UNICODE)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glm)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
#  COMMAND "${CMAKE_COMMAND}" -E copy 
#     "$<TARGET_FILE:small>"
#     "../edit/$<TARGET_FILE_NAME:small>" 
#  COMMENT "Copying to output directory")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy_directory
	"${CMAKE_CURRENT_SOURCE_DIR}/Assets/"
     "${CMAKE_CURRENT_SOURCE_DIR}/bin/Assets" 
  COMMENT "Copying to output directory")


target_include_directories(${PROJECT_NAME}
	PUBLIC include
	PUBLIC include/Engine
	PUBLIC include/Engine/Core
	PUBLIC include/Game
	PUBLIC vendor/stb_image
	PUBLIC vendor/glad/include
	#PUBLIC vendor/glad/src
	PUBLIC vendor/glfw/include
	PUBLIC vendor/spdlog/include
	PUBLIC vendor/imgui
	PUBLIC vendor/glm/glm
	#PUBLIC vendor/assimp/include
	)

#target_link_directories(${PROJECT_NAME}
		#PUBLIC vendor/glad/src
	#PUBLIC vendor/glfw/src
	#PUBLIC vendor/imgui
	#	)

target_link_libraries(${PROJECT_NAME}
		glad
	${OPENGL_LIBRARIES}
	glfw
	#imgui
	glm
  #assimp
	)
