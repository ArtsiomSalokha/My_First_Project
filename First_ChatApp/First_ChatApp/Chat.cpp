#include "Chat.h"
#include <iostream>
#include <stdexcept>

std::shared_ptr<User> Chat::findUser(const std::string& login) {
    for (auto& user : users) {
        if (user->getLogin() == login)
            return user;
    }
    return nullptr;
}

void Chat::registerUser() {
    std::string login, password, name;
    std::cout << "Введите логин: ";
    std::cin >> login;
    if (findUser(login)) throw std::runtime_error("Логин уже занят.");
    std::cout << "Введите пароль: ";
    std::cin >> password;
    std::cout << "Введите имя: ";
    std::cin >> name;
    users.push_back(std::make_shared<User>(login, password, name));
    std::cout << "Регистрация успешна.\n";
}

void Chat::loginUser() {
    std::string login, password;
    std::cout << "Логин: ";
    std::cin >> login;
    std::cout << "Пароль: ";
    std::cin >> password;
    auto user = findUser(login);
    if (!user || user->getPassword() != password)
        throw std::runtime_error("Неверный логин или пароль.");
    currentUser = user;
    std::cout << "Добро пожаловать, " << currentUser->getName() << "!\n";
}

void Chat::sendMessageToUser() {
    if (!currentUser) throw std::runtime_error("Вы не авторизованы.");
    std::string to, text;
    std::cout << "Кому отправить сообщение (логин): ";
    std::cin >> to;
    auto receiver = findUser(to);
    if (!receiver) throw std::runtime_error("Пользователь не найден.");
    std::cout << "Введите сообщение: ";
    std::cin.ignore();
    std::getline(std::cin, text);
    messages.emplace_back(currentUser->getLogin(), to, text);
    std::cout << "Сообщение отправлено.\n";
}

void Chat::sendMessageToAll() {
    if (!currentUser) throw std::runtime_error("Вы не авторизованы.");
    std::string text;
    std::cout << "Введите сообщение для всех: ";
    std::cin.ignore();
    std::getline(std::cin, text);
    for (auto& user : users) {
        if (user->getLogin() != currentUser->getLogin())
            messages.emplace_back(currentUser->getLogin(), user->getLogin(), text);
    }
    std::cout << "Сообщение отправлено всем.\n";
}

void Chat::showMessages() {
    if (!currentUser) throw std::runtime_error("Вы не авторизованы.");
    std::cout << "Ваши сообщения:\n";
    for (auto& msg : messages) {
        if (msg.getReceiver() == currentUser->getLogin() || msg.getSender() == currentUser->getLogin()) {
            std::cout << "[" << msg.getSender() << " → " << msg.getReceiver() << "]: " << msg.getContent() << "\n";
        }
    }
}
