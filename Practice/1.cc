#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <iomanip>

// Define a struct for library items
struct LibraryItem {
    std::string due_date;
    std::string status;
};

// Define a struct for fines
struct Fine {
    double early;
    double late;
    double lost_item;
};

// Function to calculate fines
double calculate_fines(const std::map<std::string, LibraryItem>& library_items, const Fine& fines) {
    double total_fine = 0.0;
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    for (const auto& item : library_items) {
        if (item.second.status == "late") {
            std::chrono::system_clock::time_point due_date = std::chrono::system_clock::from_time_t(std::stoi(item.second.due_date));
            std::chrono::duration<double> duration = today - due_date;
            total_fine += duration.count() * fines.late;
        } else if (item.second.status == "early") {
            total_fine += fines.early;
        } else if (item.second.status == "lost") {
            total_fine += fines.lost_item;
        }
    }
    return total_fine;
}

int main() {
    // Define a map of library items with their due dates and status
    std::map<std::string, LibraryItem> library_items = {
        {"book1", {"20220101", "on-time"}},
        {"book2", {"20220101", "late"}},
        {"dvd1", {"20220101", "early"}},
        {"video_game1", {"20220101", "on-time"}},
        {"laptop1", {"20220101", "lost"}}
    };

    // Define a fine struct
    Fine fines = {1.0, 2.0, 10.0};

    // Calculate fines
    double total_fine = calculate_fines(library_items, fines);

    // Print the fines
    std::cout << "Total fine: $" << std::fixed << std::setprecision(2) << total_fine << std::endl;

    return 0;
}