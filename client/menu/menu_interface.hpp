#ifndef ARCADIA_CLIENT_MENU_INTERFACE_HPP
#define ARCADIA_CLIENT_MENU_INTERFACE_HPP

#include <cstdlib>

#include "../client_includes.hpp"

void callback_menu_keyboard_down(unsigned char key, int x, int y);
void callback_menu_mouse(int button, int state, int x, int y);

#endif // ARCADIA_CLIENT_MENU_INTERFACE_HPP