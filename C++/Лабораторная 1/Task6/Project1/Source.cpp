#include <iostream>

int main() {
    long int x, y;
    std::cin >> x >> y;
    if (x % y == 0 or y % x == 0) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}