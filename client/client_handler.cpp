#include "client_handler.hpp"

bool client_handler::quit_status = 0;

bool client_handler::quit()
{
    return quit_status;
}

void client_handler::quit_client()
{
    quit_status = true;
}