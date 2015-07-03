#ifndef UIDPLUGIN_H
#define UIDPLUGIN_H

#include <iostream>
#include <curl/curl.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>

struct string {
    char *ptr;
    size_t len;
};

class UIDUtils {
	struct string httpResponse;

	public:
		std::string http_get(std::string);
		void http_post(std::string,std::string);
};

#endif
