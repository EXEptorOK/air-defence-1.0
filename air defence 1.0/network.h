#pragma once
#include "curl/curl.h"
#include "Base.h"
#include <locale>

#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")

#ifdef _DEBUG
#    pragma comment (lib,"lib/libcurl_a_debug.lib")
#else
#    pragma comment (lib,"lib/libcurl_a.lib")
#endif // _DEBUG

/*Windows Specific Additional Depenedencies*/

static int writer(char* data, size_t size, size_t nmemb, std::string* writerData);
int clientRequest(int argc, wchar_t* argv[]);;