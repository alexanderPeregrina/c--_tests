// url.cpp
#include <iostream>

#include "url.h"

URL::URL(const std::string& prot, const std::string& res) {
	protocol = prot;
	resource = res;
}
	
void URL::print() const {
	std::cout << protocol << "://" << resource << "\n";
}


  bool operator==(const URL& url1, const URL&url2)
  {
	return (url1.protocol == url2.protocol) && (url1.resource == url2.resource);
  }
