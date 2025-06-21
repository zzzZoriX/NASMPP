#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <string>

namespace NASMPPLexer {

typedef enum 
Lexeme : int {
// COMMANDS
    GLOBAL_LEX,
    SECTION_LEX,
    SECTION_NAME_LEX,
    CMP_LEX,
    LOOP_LEX,
    ENDLOOP_LEX,
    OUTPUT_LEX,
    INPUT_LEX,
    FROM_LEX,
    RETURN_LEX,
    CALL_LEX,

// SPEC SYMBOLS
    SEMIC_LEX, // !
    LPAREN_LEX, // (
    LQPAREN_LEX, // [
    LFPAREN_LEX, // {
    RPAREN_LEX, // )
    RQPAREN_LEX, // ]
    RFPAREN_LEX, // }
    ASSIGN_LEX, // =
    TWODOTS_LEX, // :
    ARROW_LEX, // =>
    INC_LEX, // ++
    DEC_LEX, // --
    COMMA_LEX, // ,

// LOGICAL SYMBOLS
    L_LEX, // <
    LE_LEX, // <=
    G_LEX, // >
    GE_LEX, // >=
    EQ_LEX, // ==
    NEQ_LEX, // != 
// NASM DOESN'T HAVE 'AND' AND 'OR' OPERATORS, SO NASM++ WILL NOT HAVE THEM ALSO

// DIRECTIVES
    DQ_LEX,
    DW_LEX,
    DD_LEX,
    DB_LEX,

// OTHER
    NUMBER_LEX,
    REG_NAME_LEX,
} Lexeme;

typedef struct 
Token {
    Lexeme lexeme;
    std::string data;
    struct Token* next;
} Token;

/**
 * @brief define tokens by word in input file
 * 
 * @return Token** 
 */
Token**
Lexer(std::ifstream);

}

#endif //LEXER_H