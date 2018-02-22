//
// Created by Kasey Stowell on 2/21/18.
//

#include <deque>
#include <stack>
#include "../include/Functions.h"

/**
 * General constructor.
 */
Functions::Functions() {
    // Empty constructor.
}

/**
 * Checks a string and determines if every opening symbol
 * has an enclosing symbol.
 * ie. parenthesis, square bracket, curley brace
 * @param input arbitrary length string.
 * @return true if all symbols are balanced.
 */
bool Functions::balancedSymbols(std::string input) {
    std::stack<char> s;
    for (char i : input) {
        if (i == '(' || i == '{' || i == '[' || i == '<')     //  Is there a starting bracket?
            s.push(i);                                        //  Push to the stack.
        if (i == ')' || i == '}' || i == ']' || i == '>') {   //  Is there an ending bracket?
            if (s.empty())                                    //  Check top of the stack for a match.
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
    // If the stack is empty, we have cleared all closing brackets.
    return s.empty();
}

/**
 * Takes an infix expression and creates the corresponding
 * postfix expression.
 * Assumes correct input.
 * @param input infix mathematical expression represented in a string.
 * @return string of the mathematical expression in postfix.
 */
std::string Functions::iToP(std::string input) {
    // Help from this algorithm online: http://csis.pace.edu/~wolf/CS122/infix-postfix.htm
    std::stack<char> op;
    std::string output;
    for (char i : input) {
        //  Print operands as they arrive.
        if (isdigit(i) || isalpha(i))
            output += i;
        // If the stack is empty or contains left parenthesis, push operator to stack.
        else if (op.empty() || op.top() == '(')
            op.push(i);
        // If incoming is left parenthesis, push to the stack.
        else if (i == '(')
            op.push(i);
        // If right parenthesis, pop stack and print until left parenthesis.
        else if (i == ')') {
            while(op.top() != '(') {
                output += op.top();
                op.pop();
            }
            // Discard left parenthesis.
            op.pop();
        }
        // If incoming has higher precedence than top of stack, push it to the stack.
        else if ((i == '*' || i == '/') && (op.top() == '+' || op.top() == '-'))
            op.push(i);
        // If incoming is equal, pop and print top of stack, push the incoming operator.
        else if ((i == '+' || i == '-') && (op.top() == '+' || op.top() == '-') ||
                ((i == '*' || i == '/') && (op.top() == '*' || op.top() == '/'))) {
            output += op.top();
            op.pop();
            op.push(i);
        }
        // If incoming has lower precedence than top of stack, pop stack and print.
        else {
            while (!op.empty() && ((i == '+' || i =='-') && (op.top() == '*' || op.top() == '/'))) {
                output += op.top();
                op.pop();
            }
            // Test incoming against new top.
            op.push(i);
        }
    }
    // Print all remaining operators on the stack.
    while (!op.empty()) {
        output += op.top();
        op.pop();
    }
    return output;
}