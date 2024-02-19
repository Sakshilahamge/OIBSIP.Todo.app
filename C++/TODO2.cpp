#include <iostream>
#include <vector>
#include <string>

void add_task(std::vector<std::string>& task_list, const std::string& item) {
    task_list.push_back(item);
}

void display_task(const std::vector<std::string>& task_list) {
    if(task_list.empty()) {
        std::cout << "Your task list is empty!" << std::endl;
    } else {
        for(int i = 0; i < task_list.size(); i++) {
            std::cout << i + 1 << ". " << task_list[i] << std::endl;
        }
    }
}

void remove_task(std::vector<std::string>& task_list, int index) {
    if(index >= 1 && index <= task_list.size()) {
        task_list.erase(task_list.begin() + index - 1);
    } else {
        std::cout << "Index out of range. Please try again." << std::endl;
    }
}

int main() {
    std::vector<std::string> task_list;
    int choice;

    while(true) {
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Display all Task" << std::endl;
        std::cout << "3. Remove Task" << std::endl;
        std::cout << "4. Completed Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::string item;
                std::cout << "Enter task item: ";
                std::cin.ignore();
                std::getline(std::cin, item);
                add_task(task_list, item);
                break;
            }
            case 2: {
                display_task(task_list);
                break;
            }
            case 3: {
                int index;
                std::cout << "Enter index of item to remove: ";
                std::cin >> index;
                remove_task(task_list, index);
                break;
            }
            case 4: {
                std::cout << "Enter index of item that is completed";
                break;
            }
            case 5: {
				return 0;
			}
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    return 0;
}
