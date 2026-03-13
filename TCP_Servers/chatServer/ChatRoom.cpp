#include "ChatRoom.hpp"
#include "ChatSession.hpp"

void ChatRoom::join(std::shared_ptr<ChatSession> session) {
    sessions_.insert(session);
}

void ChatRoom::leave(std::shared_ptr<ChatSession> session) {
    sessions_.erase(session);
}

void ChatRoom::deliver(const std::string& msg) {
    for (auto& session : sessions_) {
        session->deliver(msg);
    }
}
