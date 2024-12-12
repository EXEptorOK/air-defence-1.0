#include "network.h"

int web()
{
    WSADATA wsaData;
    char messageBuffer[10000];
    int nDataLength;
    std::string website_HTML;

    std::string url = "localhost:3000";

    std::string get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

    if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
        return 0;
    }

    SOCKET trackSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    ADDRINFO* result = NULL;
    ADDRINFO* ptr = NULL;
    ADDRINFO hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(url.c_str(), "80", &hints, &result))
    {
        std::cout << "GetAddrInfoW" << std::endl;
        WSACleanup();
        return 0;
    }

    if (connect(trackSocket, result->ai_addr, result->ai_addrlen))
    {
        std::cout << "Connected succesfully! Waiting for the response..." << std::endl;
        closesocket(trackSocket);
        return 0;
    }
    else {
        std::cout << "Connection failed!" << std::endl;
        return WSAGetLastError();
    }

    send(trackSocket, get_http.c_str(), static_cast<int>(get_http.length()), 0);

    while ((nDataLength = recv(trackSocket, messageBuffer, 10000, 0)) > 0)
    {
        int i = 0;
        while (messageBuffer[i] >= 32 || messageBuffer[i] == '\n' || messageBuffer[i] == '\r')
        {
            website_HTML += messageBuffer[i];
            i++;
        }
    }

    closesocket(trackSocket);
    WSACleanup();

    std::cout << website_HTML;
    return 0;
}




