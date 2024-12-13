#pragma once
#include "curl/curl.h"
#include "Base.h"
#include <locale>

//#ifdef _DEBUG
//#    pragma comment (lib,"lib/libcurl_a_debug.lib")
//#else
//#    pragma comment (lib,"curl/libcurl_a.lib")
//#endif // _DEBUG

/*Windows Specific Additional Depenedencies*/
#pragma comment(lib, "libcurl.lib")
#pragma comment (lib, "C://curl/curl-8.11.1/builds/libcurl-vc15-x64-release-static-ipv6-sspi-schannel/include/lib/libcurl_a.lib")
#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")

static int writer(char* data, size_t size, size_t nmemb, std::string* writerData);
int clientRequest(int argc, wchar_t* argv[]);;