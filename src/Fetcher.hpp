#ifndef FETCHER_HPP
#define FETCHER_HPP

#include <string>

class Fetcher {
public:
    std::string fetch(const std::string& url);
};

#endif