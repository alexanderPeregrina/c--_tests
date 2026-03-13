#pragma once
#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <vector>
#include "ChatRoom.hpp"

using boost::asio::ip::tcp;

class ChatSession : public std::enable_shared_from_this<ChatSession> {
public:
    ChatSession(tcp::socket socket, ChatRoom& room);

    void start();

    void deliver(const std::string& msg);

private:
    static int name_idx; 
    static std::vector<std::string> available_names; 
    std::string name_;
    void do_read() ;
    tcp::socket socket_;
    ChatRoom& room_;
    enum { max_length = 1024 };
    char data_[max_length];
};