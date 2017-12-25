#include "client_loader.hpp"

//The window we'll be rendering to
SDL_Window* client_loader::window = nullptr;
//The surface contained by the window
SDL_Surface* client_loader::screen = nullptr;
//The image we will load and show on the screen
SDL_Surface* client_loader::buffer = nullptr;
//The window renderer
SDL_Renderer* client_loader::renderer = nullptr;
//Current displayed texture
SDL_Texture* client_loader::texture = nullptr;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Surface* load_surface( const char* path )
{
    SDL_Surface* optimized_surface = nullptr;
    //Load image at specified path
    SDL_Surface* loaded_surface = IMG_Load( path );
    if( loaded_surface == nullptr )
    {
        fprintf( stderr, "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimized_surface = SDL_ConvertSurface( loaded_surface, client_loader::screen->format, 0 );
        if( optimized_surface == nullptr )
        {
            fprintf( stderr, "Unable to optimize image %s! SDL_Error: %s\n", path, SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loaded_surface );
    }
    
    return optimized_surface;
}

SDL_Texture* load_texture( const char* path )
{
    //The final texture
    SDL_Texture* new_texture = nullptr;
    
    //Load image at specified path
    //SDL_Surface* loaded_surface = IMG_Load( path );
    SDL_Surface* loaded_surface = load_surface( path );
    if( loaded_surface == nullptr )
    {
        fprintf( stderr, "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
    }
    else if( client_loader::renderer )
    {
        //Create texture from surface pixels
        new_texture = SDL_CreateTextureFromSurface( client_loader::renderer, loaded_surface );
        if( new_texture == nullptr )
        {
            fprintf( stderr, "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loaded_surface );
    }
    
    return new_texture;
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
        const int img_flags = IMG_INIT_PNG;
        if( !( IMG_Init(img_flags)&img_flags) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
        
        //Create window
        window = SDL_CreateWindow( "Arcadia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == nullptr )
        {
            fprintf( stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            screen = SDL_GetWindowSurface( window );
            
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == nullptr )
            {
                fprintf( stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
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
    if( buffer && screen)
    {
        //SDL_BlitScaled( buffer, nullptr, screen, &adjust_rect );
        SDL_BlitScaled( buffer, nullptr, screen, nullptr );
        //Update the surface
        SDL_UpdateWindowSurface( window );
    }
    else if( renderer && texture )
    {
        //Clear screen
        SDL_RenderClear( renderer );
        //Render texture to screen
        SDL_RenderCopy( renderer, texture, nullptr, nullptr );
        //Update screen
        SDL_RenderPresent( renderer );
    }
}

//Frees media and shuts down SDL 
void client_loader::close()
{
    //Deallocate surface
    SDL_FreeSurface( buffer );
    buffer = nullptr;
    SDL_FreeSurface( screen );
    screen = nullptr;
    
    //Free loaded image
    SDL_DestroyTexture( texture ); 
    texture = nullptr;
    
    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = nullptr;
    renderer = nullptr;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
