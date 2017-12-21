#include <cstdio>
#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    std::cout << "Testing output" << std::endl;
    //Start up SDL and create a window
    if( !init() )
    {
        fprintf( stderr, "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
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
                
                //Apply the image
                SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
                
                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}