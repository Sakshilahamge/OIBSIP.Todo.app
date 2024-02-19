#include <iostream>
#include <vector>
#include <string>

void add_todo(std::vector<std::string>& todo_list, const std::string& item) {
    todo_list.push_back(item);
}

void display_todo(const std::vector<std::string>& todo_list) {
    if(todo_list.empty()) {
        std::cout << "Your todo list is empty!" << std::endl;
    } else {
        for(int i = 0; i < todo_list.size(); i++) {
            std::cout << i + 1 << ". " << todo_list[i] << std::endl;
        }
    }
}

void remove_todo(std::vector<std::string>& todo_list, int index) {
    if(index >= 1 && index <= todo_list.size()) {
        todo_list.erase(todo_list.begin() + index - 1);
    } else {
        std::cout << "Index out of range. Please try again." << std::endl;
    }
}

int main() {
    std::vector<std::string> todo_list;
    int choice;

    while(true) {
        std::cout << "1. Add Todo" << std::endl;
        std::cout << "2. Display Todo" << std::endl;
        std::cout << "3. Remove Todo" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::string item;
                std::cout << "Enter todo item: ";
                std::cin.ignore();
                std::getline(std::cin, item);
                add_todo(todo_list, item);
                break;
            }
            case 2: {
                display_todo(todo_list);
                break;
            }
            case 3: {
                int index;
                std::cout << "Enter index of item to remove: ";
                std::cin >> index;
                remove_todo(todo_list, index);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    return 0;
}
