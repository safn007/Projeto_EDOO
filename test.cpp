#include <unordered_map>
#include <iostream>

int main () {
    std::unordered_map<char, int> test;
    test['a'] = 10;

    if (test.count('b') > 0) {
        std::cout << "OK\n";
    }

}