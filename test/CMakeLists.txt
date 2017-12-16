cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

project(arcadia_test)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#message(${CMAKE_SYSTEM_NAME})

if(CMAKE_SYSTEM_NAME MATCHES "WIN32")
    message("COMPILING IN WIN32")
    set(OPENGL_FLAG -lopengl32 -lglut32)
    set(DEBUG_FLAG -std=c++11 -Wall -Wextra -Werror -static-libgcc -static-libstdc++)
#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME MATCHES "APPLE")
    message("COMPILING IN APPLE")
    set(OPENGL_FLAG -framework Carbon -framework OpenGL -framework GLUT)
    set(DEBUG_FLAG -std=c++11 -Wall -Wextra -Werror)
#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("System Linux detected")
    set(OPENGL_FLAG -lGL -lGLEW -lGLU)
    set(DEBUG_FLAG -std=c++11 -Wall -Wextra -Werror)
#__________________________________________________________________________#
endif()

add_subdirectory(client)
add_subdirectory(server)