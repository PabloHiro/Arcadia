#ifndef ARCADIA_CLIENT_MENU_MAIN_HPP
#define ARCADIA_CLIENT_MENU_MAIN_HPP

#include "../client_includes.hpp"
#include "../client_handler.hpp"
#include "../client_loader.hpp"

class menu_main
{
    public:
    
    static void load();
    
    void to_single_player();
    
    void to_multi_player();
    
    void to_configuration();

    static void event_handler(SDL_Event event);
};

#endif // ARCADIA_CLIENT_MENU_MAIN_HPP