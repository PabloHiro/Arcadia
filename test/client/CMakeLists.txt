cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

project(arcadia_client_test)

set(CLIENT_DIRECTORY ${CMAKE_SOURCE_DIR}/client)
set(CLIENT_MENU_DIRECTORY
#    ${CLIENT_DIRECTORY}/menu/menu_main.cpp
#    ${CLIENT_DIRECTORY}/menu/menu_interface.cpp
#    ${CLIENT_DIRECTORY}/menu/menu_single_player.cpp
#    ${CLIENT_DIRECTORY}/menu/menu_multi_player.cpp
)

#add_executable(opengl_version opengl_version.cpp)
#target_include_directories(opengl_version PRIVATE ${CLIENT_DIRECTORY} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
#target_link_libraries(opengl_version ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
#target_compile_options(opengl_version PRIVATE ${DEBUG_FLAG} ${OPENGL_FLAG})


add_executable(menu menu.cpp ${CLIENT_MENU_DIRECTORY})
target_include_directories(menu PRIVATE ${CLIENT_DIRECTORY} ${SDL2_INCLUDE_DIRS} )
target_link_libraries(menu ${SDL2_LIBRARIES} )
target_compile_options(menu PRIVATE ${DEBUG_FLAG} ${SDL_FLAG})

#Call tests with make test

#set(TESING_REGEX "doesn't work properly: ")
#add_test( caesar crypt_test caesar.xml)
#set_tests_properties( caesar PROPERTIES FAIL_REGULAR_EXPRESSION ${TESING_REGEX})