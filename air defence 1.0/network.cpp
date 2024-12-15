#pragma once
#include "network.h"

#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")

#ifdef _DEBUG
#    pragma comment (lib,"libcurl_a_debug.lib")
#else
#    pragma comment (lib,"libcurl_a.lib")
#endif // _DEBUG

static int writer(char* data, size_t size, size_t nmemb, std::string* writerData) {
    if (writerData == NULL) {
        return 0;
    }
    writerData->append(data, size * nmemb);
    return size * nmemb;
}

int clientRequest(int argc, wchar_t* argv[]) {
    std::cout << "My lovely curl!" << std::endl;

    std::string content;

    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = nullptr;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

        CURLcode response = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    std::cout << content << std::endl;
    return 0;
}




