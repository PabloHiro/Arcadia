#include "menu_interface.hpp"


void callback_menu_keyboard_down(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27: //ESC
        {
            exit(1);
            break;
        }
    }
}

void callback_menu_mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
       // Conditionals checking coordinates
    }
}