#ifndef ARCADIA_CLIENT_CLIENT_HANDLER_HPP
#define ARCADIA_CLIENT_CLIENT_HANDLER_HPP

#include "client_includes.hpp"

class client_handler
{
    public:
    
    static bool quit();
    
    static void quit_client();
    
    private:
    
    static bool quit_status;
};
#endif // ARCADIA_CLIENT_CLIENT_HANDLER_HPP