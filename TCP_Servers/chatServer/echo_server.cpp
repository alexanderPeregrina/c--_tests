#include <boost/asio.hpp>
#include <iostream>

// To compile: g++ echo_server.cpp -o echo_server -lboost_system -lpthread
using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io;

        // Listen on port 12345
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Echo server running on port 12345...\n";

        for (;;) {
            tcp::socket socket(io);
            acceptor.accept(socket);

            std::cout << "Client connected!\n";

            for (;;) {
                char data[1024];
                boost::system::error_code error;

                // Read from client
                size_t length = socket.read_some(boost::asio::buffer(data), error);

                if (error == boost::asio::error::eof) {
                    std::cout << "Client disconnected.\n";
                    break; // connection closed cleanly
                } else if (error) {
                    throw boost::system::system_error(error);
                }

                // Echo back to client
                boost::asio::write(socket, boost::asio::buffer(data, length));
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}