#pragma once
#include <winsock2.h>
#include <WS2tcpip.h>
#include "Base.h"
#include <http.h>
#include <locale>
#define CURL_STATICLIB
#include "curl/curl.h"

#ifdef _DEBUG
#    pragma comment (lib,"curl/libcurl_a_debug.lib")
#else
#    pragma comment (lib,"curl/libcurl_a.lib")
#endif // _DEBUG

/*Windows Specific Additional Depenedencies*/
#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")

int web();






