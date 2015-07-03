#include "UIDPlugin.h"
#include <stdlib.h>
#include <string.h>

size_t writeCallback(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    s->len = 0;
    s->ptr = (char *) malloc(s->len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';

    size_t new_len = s->len + size*nmemb;
    s->ptr = (char *) realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

std::string UIDUtils::http_get(std::string uri)
{
    CURL *AJcurl = curl_easy_init();
    std::string response;

    if(AJcurl) {
	curl_easy_setopt(AJcurl, CURLOPT_URL, uri.c_str());

	/* use a GET to fetch this */
//        curl_easy_setopt(AJcurl,CURLOPT_HTTPGET,1L);

	curl_easy_setopt(AJcurl, CURLOPT_WRITEFUNCTION, writeCallback);
	curl_easy_setopt(AJcurl, CURLOPT_WRITEDATA, &httpResponse);

        /* Perform the request, res will get the return code */
        if(curl_easy_perform(AJcurl))
	      std::cerr << "curl_easy_perform() failed"<< std::endl;

	response = (std::string) httpResponse.ptr;

	free(httpResponse.ptr);

        /* always cleanup */
        curl_easy_cleanup(AJcurl);
    }

    curl_global_cleanup();

    return response; 
}

void UIDUtils::http_post(std::string uri,std::string payLoad)
{	
	CURL *AJcurl = curl_easy_init();

	if(AJcurl) {
        	curl_easy_setopt(AJcurl, CURLOPT_URL, uri.c_str());

        	/* use a GET to fetch this */
	        curl_easy_setopt(AJcurl,CURLOPT_POSTFIELDS,payLoad.c_str());

        	/* Perform the request, res will get the return code */
	        if(curl_easy_perform(AJcurl))
			std::cerr << "curl_easy_perform() failed"<< std::endl;

	        /* always cleanup */
        	curl_easy_cleanup(AJcurl);
    	}
	
	curl_global_cleanup();
}
