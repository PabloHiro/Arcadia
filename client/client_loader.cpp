#include "client_loader.hpp"

//The window we'll be rendering to
SDL_Window* client_loader::window = NULL;
//The surface contained by the window
SDL_Surface* client_loader::screen = NULL;
//The image we will load and show on the screen
SDL_Surface* client_loader::buffer = NULL;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Surface* load_surface( const char* path )
{
    SDL_Surface* optimized_surface = NULL;
    //Load image at specified path
    SDL_Surface* loaded_surface = IMG_Load( path );
    if( loaded_surface == NULL )
    {
        fprintf( stderr, "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimized_surface = SDL_ConvertSurface( loaded_surface, client_loader::screen->format, NULL );
        if( optimized_surface == NULL )
        {
            fprintf( stderr, "Unable to optimize image %s! SDL_Error: %s\n", path, SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loaded_surface );
    }
    
    return optimized_surface;
}



client_loader::~client_loader()
{
    close();
}

//Starts up SDL and creates window 
bool client_loader::initialize()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Arcadia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            fprintf( stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        
        const int img_flags = IMG_INIT_PNG;
        if( !( IMG_Init(img_flags)&img_flags) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
        
        if(success)
        {
            //Get window surface
            screen = SDL_GetWindowSurface( window );
        }
    }

    return success;
}

void client_loader::display()
{
    /*
    //Apply the image stretched
    SDL_Rect adjust_rect;
    adjust_rect.x = 156;
    adjust_rect.y = 0;
    adjust_rect.w = 1024;
    adjust_rect.h = 768;
    */
    //SDL_BlitScaled( buffer, NULL, screen, &adjust_rect );
    SDL_BlitScaled( buffer, NULL, screen, NULL );
}

//Frees media and shuts down SDL 
void client_loader::close()
{
    //Deallocate surface
    SDL_FreeSurface( buffer );
    buffer = NULL;
    
    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}
