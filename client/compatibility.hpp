#ifndef ARCADIA_CLIENT_COMPATIBILITY_HPP
#define ARCADIA_CLIENT_COMPATIBILITY_HPP

#if defined(_WIN32) //Windows

#elif defined(__APPLE__) //Apple

#elif defined(unix) || defined(__unix__) || defined(__unix) //Linux
    #include <GL/glew.h>
    #include <GL/freeglut.h>
    #include <GL/glut.h>
    
#endif

#endif //ARCADIA_CLIENT_COMPATIBILITY_HPP