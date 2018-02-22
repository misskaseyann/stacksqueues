#include <iostream>
#include "include/Functions.h"

int main() {
    std::cout << "Start Test!" << std::endl;
    Functions f;
    std::string s = "[df]";
    bool t = f.balancedSymbols(s);
    if (t) {
        std::cout << "Functioning statement!" << std::endl;
    } else {
        std::cout << "BAD!" << std::endl;
    }
    s = "A*(B+C*D)+E";
    s = f.iToP(s);
    std::cout << s;
    return 0;
}