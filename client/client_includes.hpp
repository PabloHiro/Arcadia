#ifndef ARCADIA_CLIENT_CLIENT_INCLUDES_HPP
#define ARCADIA_CLIENT_CLIENT_INCLUDES_HPP

#if defined(_WIN32) //Windows
    #include <SDL.h>
#elif defined(__APPLE__) //Apple

#elif defined(unix) || defined(__unix__) || defined(__unix) //Linux
    #include <SDL2/SDL.h>
#endif

#endif //ARCADIA_CLIENT_CLIENT_INCLUDES_HPP