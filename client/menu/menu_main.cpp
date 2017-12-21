#include "menu_main.hpp"

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