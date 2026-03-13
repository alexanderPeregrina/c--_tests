#pragma once
#include <boost/asio.hpp>
#include "ChatRoom.hpp"

using boost::asio::ip::tcp;


class ChatServer {
public:
    ChatServer(boost::asio::io_context& io, short port);

private:
    void do_accept();
    tcp::acceptor acceptor_;
    ChatRoom room_;
};
