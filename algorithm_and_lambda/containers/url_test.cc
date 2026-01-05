// main.cpp
#include <iostream>
#include <list>
#include <vector> 
#include <string>
#include <utility>
#include "url.h"

using namespace std;

class StoreUlr
{
  static vector<URL> url_list;
  static pair<bool, int> url_exists(const URL& url)
  {
    int index = 0;
    for (auto it : url_list)
    {
      if (it == url)
        return {true, index};
      ++index;
    }
    return {false, index};
  }
  public: 
    static void add_url(const URL& url)
    {
      pair<bool, int> result = url_exists(url);
      if (result.first)
      {
        auto it = begin(url_list);
        advance(it, result.second);
        url_list.erase(it);
      }  
      url_list.push_back(url);
    }

    static void show_urls()
    {
      for(auto it : url_list)
      {
        it.print();
      }
    }
};


vector<URL> StoreUlr::url_list;


int main() {
    

    URL url1("http", "example.com/index.html");
    URL url2("https", "hello.com/index.html");
    URL url3("http", "example.com/index.html");
    URL url4("http", "youtube.com/index.html");
    URL url5("http", "facebook.com/index.html");
    URL url6("http", "linkedin.com/index.html");
    URL url7("http", "Robotics.com/index.html");


    StoreUlr::add_url(url1);
    StoreUlr::add_url(url2);
    StoreUlr::add_url(url3);
    StoreUlr::add_url(url4);
    StoreUlr::add_url(url5);
    StoreUlr::add_url(url6);
    StoreUlr::add_url(url7);

    StoreUlr::show_urls();


}