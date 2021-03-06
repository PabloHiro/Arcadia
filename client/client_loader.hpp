#ifndef ARCADIA_CLIENT_CLIENT_LOADER_HPP
#define ARCADIA_CLIENT_CLIENT_LOADER_HPP

#include <cstdio>

#include "client_includes.hpp"

SDL_Surface* load_surface( const char* path );
SDL_Texture* load_texture( const char* path );

class client_loader
{
    public:
    
    ~client_loader();
        
    static SDL_Window* window;
    
    static SDL_Surface* screen;
    
    static SDL_Surface* buffer;
    
    static SDL_Renderer* renderer;
    
    static SDL_Texture* texture;
    
    static bool initialize();
    
    static void display();
    
    static void close();
};

#endif //ARCADIA_CLIENT_CLIENT_LOADER_HPP