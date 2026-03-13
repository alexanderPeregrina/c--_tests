#include "ChatSession.hpp"

int ChatSession::name_idx = 0; // Initialize static member
std::vector<std::string> ChatSession::available_names = {"Alice", "Bob", "Charlie", "Dave", "Eve"}; //

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room)
    : socket_(std::move(socket)), room_(room) 
    {
      name_ = available_names[name_idx++ % available_names.size()]; // assign a name
    }

void ChatSession::start() {
    room_.join(shared_from_this()); 
    do_read();
}

void ChatSession::deliver(const std::string& msg) {
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(msg),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
            if (ec) {
                room_.leave(shared_from_this());
            }
        });
}

void ChatSession::do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string msg(data_, length);
                room_.deliver(name_ + ": " + msg); // broadcast to all clients
                do_read(); // keep reading
            } else {
                room_.leave(shared_from_this());
            }
        });
}