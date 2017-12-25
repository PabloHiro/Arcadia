cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

project(arcadia_client_test)

#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)

add_compile_options(-Wall -Wextra)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
#find_package(SDL2_ttf REQUIRED)

set(CLIENT_DIRECTORY ${CMAKE_SOURCE_DIR}/client)
set(CLIENT_DIRECTORY_SRC
    ${CLIENT_DIRECTORY}/client_handler.cpp
    ${CLIENT_DIRECTORY}/client_loader.cpp
)

set(CLIENT_MENU_DIRECTORY ${CMAKE_SOURCE_DIR}/client/menu)
set(CLIENT_MENU_DIRECTORY_SRC
    ${CLIENT_MENU_DIRECTORY}/menu_main.cpp
#    ${CLIENT_MENU_DIRECTORY}/menu_single_player.cpp
#    ${CLIENT_MENU_DIRECTORY}/menu_multi_player.cpp
)

message(${CMAKE_SYSTEM_NAME})
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("System Windows detected")
    #-Wl,-subsystem,-mwindows to supress the output
    add_compile_options(-std=c++11 -fno-exceptions -static-libgcc -static-libstdc++)
#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME MATCHES "APPLE")
    message("System Apple detected")
    #set(OPENGL_FLAG -framework Carbon -framework OpenGL -framework GLUT)
    #set(DEBUG_FLAG -std=c++11 -Wall -Wextra -Werror)
#__________________________________________________________________________#
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("System Linux detected")
    add_compile_options(-std=c++11 -static-libgcc -static-libstdc++)
#__________________________________________________________________________#
endif()


#add_executable(opengl_version opengl_version.cpp)
#target_include_directories(opengl_version PRIVATE ${CLIENT_DIRECTORY} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
#target_link_libraries(opengl_version ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
#target_compile_options(opengl_version PRIVATE ${DEBUG_FLAG} ${OPENGL_FLAG})

add_executable(menu menu.cpp ${CLIENT_DIRECTORY_SRC} ${CLIENT_MENU_DIRECTORY_SRC})
target_include_directories(menu PRIVATE ${CLIENT_DIRECTORY} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(menu ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
#target_compile_options(menu PRIVATE ${DEBUG_FLAG})
add_custom_command(
        TARGET menu POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/resources
                ${CMAKE_CURRENT_BINARY_DIR}/resources
)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_custom_command(
            TARGET menu POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/lib/runtime
                    ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()
#Call tests with make test

#set(TESING_REGEX "doesn't work properly: ")
#add_test( caesar crypt_test caesar.xml)
#set_tests_properties( caesar PROPERTIES FAIL_REGULAR_EXPRESSION ${TESING_REGEX})