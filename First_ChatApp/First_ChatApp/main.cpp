#include "Chat.h"
#include <iostream>

int main() {
    
    setlocale(LC_ALL, "");
    
    Chat chat;
    while (true) {
        try {
            std::cout << "\n1. �����������\n2. ����\n3. ������ ���������\n4. ��������� ����\n5. �������� ���������\n0. �����\n�����: ";
            int choice;
            std::cin >> choice;
            switch (choice) {
            case 1: chat.registerUser(); break;
            case 2: chat.loginUser(); break;
            case 3: chat.sendMessageToUser(); break;
            case 4: chat.sendMessageToAll(); break;
            case 5: chat.showMessages(); break;
            case 0: return 0;
            default: std::cout << "�������� �����.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "������: " << e.what() << "\n";
        }
    }
}
