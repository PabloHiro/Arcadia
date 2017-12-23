#include <cstdio>
#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    //Start up SDL and create a window
    if( !client_loader::initialize() )
    {
        fprintf( stderr, "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        client_loader::buffer = menu_main::load();
        
        if( !client_loader::buffer )
        {
            fprintf( stderr, "Failed to load media!\n" );
        }
        else
        {
            //Event handler
            SDL_Event event;

            //While application is running
            while( !client_handler::quit() )
            {
                //Handle events on queue
                menu_main::event_handler(event);
                
                client_loader::display();
                
                //Update the surface
                SDL_UpdateWindowSurface( client_loader::window );
            }
        }
    }
    
    //Free resources and close SDL
    client_loader::close();
    
    return 0;
}