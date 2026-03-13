#include <boost/asio.hpp>
#include <iostream>

// To compile: g++ test_asio.cpp -o test_asio -lboost_system -lpthread

int main() {
    boost::asio::io_context io;
    std::cout << "Boost.Asio is working!" << std::endl;
    return 0;
}