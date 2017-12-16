#include "menu_interface.hpp"

#define KEY_ESC 27

void callback_keyboard_down(unsigned char key, int x, int y)
{
    switch(key)
    {
        case KEY_ESC:
        {
            exit(1);
            break;
        }
    }
}