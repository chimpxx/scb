cmake_minimum_required(VERSION 3.5)

set(PROJ_NAME scb)

project(${PROJ_NAME})

file(GLOB_RECURSE SB_SOURCES "*.cpp")
file(GLOB_RECURSE SB_HEADERS "*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

#set flags
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -g")

#set up linux search paths
set(LIBRARY_SEARCH_PATH
        /usr/lib
        /usr/lib32
        /usr/lib64
        )


set(HEADER_SEARCH_PATH
        /usr/include
        )


# Find OpenGL
find_package(OpenGL)
find_package(X11)


# Find glfw header
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h ${HEADER_SEARCH_PATH})


# Find glfw library
find_library(GLFW_LIBRARIES libglfw ${LIBRARY_SEARCH_PATH})


# Set additional libs
set( LIBRARY_SEARCH_PATH
        -lGLEW
        -lSOIL
        -lBox2D
        -lglfw
        -lGL
        -ldl
        -lX11
        -lXi
        -lXrandr
        -lXxf86vm
        -lXinerama
        -lXcursor
        -lrt
        -lm
        -pthread
        )


# Include directories for this project
set(INCLUDE_PATH
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        )


# Libraries needed on all platforms for this project
set(LIBRARIES
        ${OPENGL_LIBRARIES}
        ${LIBRARY_SEARCH_PATH}
        ${X11_LIBRARIES}
        ${ADDITIONAL_LIBS}
        )

# Windows and Linux need GLEW, the OpenGL Extension Wrangler
find_path(GLEW_INCLUDE_DIR GL/glew.h
        ${HEADER_SEARCH_PATH}
        )


set(INCLUDE_PATH ${INCUDE_PATH}
        ${GLEW_INCLUDE_DIR}
        )

set(EXECUTABLE_OUTPUT_PATH "")

# Add a target executable
set (SB_INCLUDE_DIRS "")
foreach (_headerFile ${SB_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND SB_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES SB_INCLUDE_DIRS)

include_directories(${SB_INCLUDE_DIRS})
add_executable (scb ${SB_SOURCES})

# Libraries to be linked
target_link_libraries(${PROJ_NAME}
        ${LIBRARIES}
        )