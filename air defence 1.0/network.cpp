#include "network.h"
#include "qnetwork.h"

if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
{
    error = WSAGetLastError();
}

if (INVALID_SOCKET == (trackSocket = socket(AF_INET, SOCK_STREAM, 0)))
{
    // Error...
    error = WSAGetLastError();
    // ... 
}