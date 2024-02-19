#include<iostream>

int main() {
    int d1, m1, y1, d2, m2, y2;

    std::cout << "Enter the return date in the format: d m y" << std::endl;
    std::cin >> d2 >> m2 >> y2;

    std::cout << "Enter the due date in the format: d m y" << std::endl;
    std::cin >> d1 >> m1 >> y1;

    int fine = 0;
    if(y2 > y1) {
        fine = 10000;
    } else if(y2 == y1) {
        if(m2 > m1) {
            fine = 500 * (m2 - m1);
        } else if(m2 == m1) {
            if(d2 > d1) {
                fine = 15 * (d2 - d1);
            }
        }
    }

    std::cout << "Fine: " << fine << std::endl;

    return 0;
}