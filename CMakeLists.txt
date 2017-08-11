cmake_minimum_required(VERSION 3.6)
project(learningOpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

##############################################################
# Project folder structure
##############################################################
set(EXTERNAL_LIBRARIES ext)
set(SOURCE_FILES src)

##############################################################
# Build ext
##############################################################
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${PROJECT_SOURCE_DIR}/${EXTERNAL_LIBRARIES}/glfw-3.2.1)
add_subdirectory(${PROJECT_SOURCE_DIR}/${EXTERNAL_LIBRARIES}/glad)

##############################################################
# Includes
##############################################################
include_directories("${EXTERNAL_LIBRARIES}/glad/include")
include_directories("${EXTERNAL_LIBRARIES}/stb_image")
include_directories("${EXTERNAL_LIBRARIES}/glm-0.9.8.4")

##############################################################
# Build Program
##############################################################
add_executable(learningOpenGL
        ${SOURCE_FILES}/main.cpp
        ${SOURCE_FILES}/Shader/Shader.cpp
        ${SOURCE_FILES}/Shader/Shader.h
        ${SOURCE_FILES}/camera.h)
target_link_libraries(learningOpenGL glfw)
target_link_libraries(learningOpenGL glad)


##############################################################
# Configuration and Copying Resource Files
##############################################################
add_custom_command(TARGET learningOpenGL PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources)
