#ifndef ARCADIA_CLIENT_CLIENT_LOADER_HPP
#define ARCADIA_CLIENT_CLIENT_LOADER_HPP

#include <cstdio>

#include "client_includes.hpp"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


SDL_Surface* loadSurface( const char* path )
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
    }
    
    return loadedSurface;
}

//Starts up SDL and creates window 
bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    
    return success;
}

//Loads media 
bool loadMedia()
{
    //Loading succes flag
    bool success = true;
    //Load splash image
    gHelloWorld = loadSurface( "resources/tzar_menu.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Failed to load image: resources/tzar_menu.bmp\n" );
        success = false;
    }
    return success;
}

//Frees media and shuts down SDL 
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}


#endif //ARCADIA_CLIENT_CLIENT_LOADER_HPP