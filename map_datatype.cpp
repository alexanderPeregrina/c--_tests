#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> age;

    age["Alice"] = 30;
    age["Bob"] = 25;
    age["Charlie"] = 35;

    for (const auto& pair : age) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
