// url.h
#ifndef URL_H
#define URL_H

#include <string>

class URL {
    std::string protocol;
    std::string resource;
public:
    URL(const std::string& prot, const std::string& res);
    void print() const;

  friend bool operator==(const URL& url1, const URL&url2);
};

#endif //URL_H