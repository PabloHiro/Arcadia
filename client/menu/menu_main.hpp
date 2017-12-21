#ifndef ARCADIA_CLIENT_MENU_MAIN_HPP
#define ARCADIA_CLIENT_MENU_MAIN_HPP

#include "../client_includes.hpp"
#include "../client_handler.hpp"

class menu_main
{
    public:
    
    void display();
    
    void move_to_single_player();
    
    void move_to_multi_player();
    
    void move_to_configuration();

    static void event_handler(SDL_Event event);
};

#endif // ARCADIA_CLIENT_MENU_MAIN_HPP