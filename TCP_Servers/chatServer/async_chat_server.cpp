#include <boost/asio.hpp>
#include <iostream>
#include <set>
#include <memory>
#include <string>
#include "ChatServer.hpp"

// To compile: g++ async_chat_server.cpp ChatServer.cpp ChatSession.cpp ChatRoom.cpp -o async_chat_server -lboost_system -lpthread

int main() {
    try {
        boost::asio::io_context io;
        ChatServer server(io, 12345);

        std::cout << "Chat server running on port 12345...\n";
        io.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}