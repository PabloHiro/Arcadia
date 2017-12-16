#include <stdio.h>

#include "compatibility.hpp"
#include "menu/menu_interface.hpp"


static void callback_display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    /*This call initializes GLUT. The parameters can be provided directly from the command line and include
    useful options such as '-sync' and '-gldebug' which disable the asynchronous nature of X and automatically
    checks for GL errors and displays them (respectively).*/

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    /*Here we configure some GLUT options. GLUT_DOUBLE enables double buffering (drawing to a background buffer
    while another buffer is displayed) and the color buffer where most rendering ends up (i.e. the screen).*/
    
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test::Menu");
    /*These calls specify the window parameters and create it. You also have the option to specify the window title.*/
    
    glutDisplayFunc(callback_display_func);
    /*Since we are working in a windowing system most of the interaction with the running program occurs via event
    callback functions. GLUT takes care of interacting with the underlying windowing system and provides us with a
    few callback options. Here we use just one - a "main" callback to do all the rendering of one frame. This
    function is continuously called by GLUT internal loop. */
    
    glutKeyboardFunc(callback_keyboard_down);
    
    
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    /* The color has four channels (RGBA) and it is specified as a normalized value between 0.0 and 1.0. */
    
    glutMainLoop();
    /*This call passes control to GLUT which now begins its own internal loop. In this loop it listens to events 
    from the windowing system and passes them via the callbacks that we configured. In our case GLUT will only call 
    the function we registered as a display callback (callback_display_func) to give us a chace to render the frame. */
    
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    return 0;
}