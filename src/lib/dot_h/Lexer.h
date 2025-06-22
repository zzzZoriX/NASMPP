#ifndef LEXER_H
#define LEXER_H

#include "Common.h"
#include "ErrorHandler.h"

#include <fstream>
#include <string>

namespace NASMPPLexer {

typedef enum 
Lexeme : s32 {
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
    UNDEFINE_LEX
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
Token*
Lexer(std::ifstream&);

/**
 * @brief define lexeme by word
 * 
 * @return Lexeme 
 */
Lexeme
_define_lexeme(const std::string&);

/**
 * @brief checks symbol for if it is a specific symbol return true else false
 * 
 * @return true 
 * @return false 
 */
bool
is_spec(const s8);

/**
 * @brief checks str for if it is a specific string return true else false
 * 
 * @return true 
 * @return false 
 */
bool
is_spec_str(const std::string&);

// overload
bool
is_spec_str(const s8*);

/**
 * @brief checks str for if it is a register name
 * 
 * @return true 
 * @return false 
 */
bool
is_reg_name(const std::string&);

}

#endif //LEXER_H