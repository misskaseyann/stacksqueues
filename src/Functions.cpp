//
// Created by Kasey Stowell on 2/21/18.
//

#include <deque>
#include <stack>
#include "../include/Functions.h"

Functions::Functions() {
    // Constructor
}

bool Functions::balancedSymbols(std::string input) {
    std::stack<char> s;
    for (char i : input) {
        if (i == '(' || i == '{' || i == '[' || i == '<')
            s.push(i);
        if (i == ')' || i == '}' || i == ']' || i == '>') {
            if (s.empty())
                return false;
            else if (s.top() == '[' && i == ']')
                s.pop();
            else if (s.top() == '{' && i == '}')
                s.pop();
            else if (s.top() == '(' && i == ')')
                s.pop();
            else if (s.top() == '<' && i == '>')
                s.pop();
        }
    }
    return s.empty();
}

std::string Functions::iToP(std::string input) {
    std::stack<char> op;
    std::string output;
    for (char i : input) {
        if (isdigit(i) || isalpha(i)) {
            output += i;
        }
        else if (op.empty() || op.top() == '(') {
            op.push(i);
        }
        else if (i == '(') {
            op.push(i);
        }
        else if (i == ')') {
            while(op.top() != '(') {
                output += op.top();
                op.pop();
            }
            op.pop();
        }
        else if ((i == '*' || i == '/') && (op.top() == '+' || op.top() == '-')) {
            op.push(i);
        }
        else if ((i == '+' || i == '-') && (op.top() == '+' || op.top() == '-') ||
                ((i == '*' || i == '/') && (op.top() == '*' || op.top() == '/'))) {
            output += op.top();
            op.pop();
            op.push(i);
        }
        else {
            while (!op.empty() && ((i == '+' || i =='-') && (op.top() == '*' || op.top() == '/'))) {
                output += op.top();
                op.pop();
            }
            op.push(i);
        }
    }
    while (!op.empty()) {
        output += op.top();
        op.pop();
    }
    return output;
}