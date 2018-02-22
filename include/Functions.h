//
// Created by Kasey Stowell on 2/21/18.
//

#ifndef STACKSQUEUES_FUNCTIONS_H
#define STACKSQUEUES_FUNCTIONS_H

#include <iostream>

class Functions{
    public:
        /**
         * General constructor for the class.
         */
        Functions();
        
        /**
         * Checks a string and determines if every opening symbol
         * has an enclosing symbol.
         * ie. parenthesis, square bracket, curley brace
         * @param input arbitrary length string.
         * @return true if all symbols are balanced.
         */
        bool balancedSymbols(std::string input);
        
        /**
         * Takes an infix expression and creates the corresponding
         * postfix expression.
         * @param input infix mathematical expression represented in a string.
         * @return string of the mathematical expression in postfix.
         */
        std::string iToP(std::string input);
};

#endif //STACKSQUEUES_FUNCTIONS_H
