#pragma once
#include <vector>
#include <memory>
#include <string>
#include "User.h"
#include "Message.h"

class Chat {
public:
    void registerUser();
    void loginUser();
    void sendMessageToUser();
    void sendMessageToAll();
    void showMessages();

private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<Message<std::string>> messages;
    std::shared_ptr<User> currentUser = nullptr;

    std::shared_ptr<User> findUser(const std::string& login);
};

