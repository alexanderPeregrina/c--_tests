#pragma once
#include <set>
#include <string>
#include <memory>

class ChatSession;

// Shared state: keeps track of all active sessions
class ChatRoom {
public:
    void join(std::shared_ptr<ChatSession> session);

    void leave(std::shared_ptr<ChatSession> session);

    void deliver(const std::string& msg);

private:
    std::set<std::shared_ptr<ChatSession>> sessions_;
};