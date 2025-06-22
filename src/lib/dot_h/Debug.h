#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <iterator>
#include "Lexer.h"

inline void DEBUG_PRINT_TOKENS(NASMPPLexer::Token* t){
    NASMPPLexer::Token* c = t;
    while(c){
        std::cout << c->data << std::endl;
        c = c->next;
    }
}
#endif //DEBUG_H