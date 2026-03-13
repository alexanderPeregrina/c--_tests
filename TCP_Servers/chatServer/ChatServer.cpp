#include "ChatServer.hpp"
#include "ChatSession.hpp"
#include "ChatRoom.hpp"

ChatServer::ChatServer(boost::asio::io_context& io, short port)
    : acceptor_(io, tcp::endpoint(tcp::v4(), port)), room_() {
    do_accept();
}

void ChatServer::do_accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::make_shared<ChatSession>(std::move(socket), room_)->start();
            }
            do_accept(); // accept next client
        });
}
