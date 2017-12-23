#include "menu_main.hpp"


SDL_Surface* menu_main::load()
{
    SDL_Surface* screen_surface;
    //screen_surface = load_surface( "resources/main_menu.bmp" );
    screen_surface = load_surface( "resources/main_menu.png" );
    
    return screen_surface;
}
void menu_main::event_handler(SDL_Event event)
{
    while( SDL_PollEvent( &event ) )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            client_handler::quit_client();
        }
        else if( event.type == SDL_KEYDOWN )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                {
                    client_handler::quit_client();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}