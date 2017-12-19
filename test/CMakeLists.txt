cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

project(arcadia_test)

#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)

message(${CMAKE_SYSTEM_NAME})
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("System Windows detected")
    #set(OPENGL_FLAG -lopengl32 -lglut32)
    set(SDL_FLAG -lSDL2main -lSDL2)
    set(DEBUG_FLAG -lmingw32 -Wl,-subsystem,windows)

#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME MATCHES "APPLE")
    message("System Apple detected")
    #set(OPENGL_FLAG -framework Carbon -framework OpenGL -framework GLUT)
    #set(DEBUG_FLAG -std=c++11 -Wall -Wextra -Werror)
#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("System Linux detected")
    #set(OPENGL_FLAG -lGL -lGLEW -lGLU)
    set(SDL_FLAG -lSDL2)
    set(DEBUG_FLAG -std=c++11 -Wall -Wextra)
#__________________________________________________________________________#
endif()

add_subdirectory(client)
add_subdirectory(server)