#include "../dot_h/Lexer.h"
using namespace NASMPPLexer;

static inline Token*
_create_token(std::string& word){
    Token* token = new Token;

    Lexeme lexeme = _define_lexeme(word);
    if(lexeme == UNDEFINE_LEX)
        _abort_w_msg(
            "unknown word - " + word, // TODO: make more info in error like row and column
            1
        );

        
    token->data = word;
    token->lexeme = lexeme;
    word.clear();

    return token;
}

Token*
NASMPPLexer::Lexer(std::ifstream& ifp){
    Token
        * tokens,
        * current_token = tokens
    ;

    std::string word("");
    s8 c;

    while((c = ifp.get()) != EOF){
        if(c == ' ' || is_spec(c)){
            current_token = _create_token(word);
            current_token->next = new Token;
            current_token = current_token->next;

            if(c == ' ') continue;
        }
        if(is_spec(c)){
            s8 maybe_spec_str[3] {c, static_cast<s8>(ifp.get()), '\0'};
            
            if(!is_spec_str(maybe_spec_str)){
                ifp.unget();
                word += c;
            }
            else
                word = maybe_spec_str;

            current_token = _create_token(word);
            current_token->next = new Token;
            current_token = current_token->next;
        }
        if(isdigit(c)){
            if(word[0] == 'r') // because it may be register
                break;         // but all registers with num in name
                               // starts with 'r' (r8b, r10d and etc.)

            current_token = _create_token(word);
            current_token->next = new Token;
            current_token = current_token->next;

            while(isdigit(c)){
                word += c;
                c = ifp.get();
            }

            current_token = _create_token(word);
            current_token->next = new Token;
            current_token = current_token->next;
        }

        word += c;
    }

    return tokens;
}

Lexeme
NASMPPLexer::_define_lexeme(const std::string& str){
    if(str == "global")     return GLOBAL_LEX;
    if(str == "section")    return SECTION_LEX;
    if(str[0] == '.')       return SECTION_NAME_LEX;
    if(str == "cmp")        return CMP_LEX;
    if(str == "loop")       return LOOP_LEX;
    if(str == "endloop")    return ENDLOOP_LEX;
    if(str == "output")     return OUTPUT_LEX;
    if(str == "input")      return INPUT_LEX;
    if(str == "from")       return FROM_LEX;
    if(str == "return")     return RETURN_LEX;
    if(str == "call")       return CALL_LEX;

    if(str[0] == '!')       return SEMIC_LEX;
    if(str[0] == '(')       return LPAREN_LEX;
    if(str[0] == '[')       return LQPAREN_LEX;
    if(str[0] == '{')       return LFPAREN_LEX;
    if(str[0] == ')')       return RPAREN_LEX;
    if(str[0] == ']')       return RQPAREN_LEX;
    if(str[0] == '}')       return RFPAREN_LEX;
    if(str[0] == '=')       return ASSIGN_LEX;
    if(str[0] == ':')       return TWODOTS_LEX;
    if(str == "=>")         return ARROW_LEX;
    if(str == "++")         return INC_LEX;
    if(str == "--")         return DEC_LEX;
    if(str[0] == ',')       return COMMA_LEX; 

    if(str[0] == '<')       return L_LEX;
    if(str == "<=")         return LE_LEX;
    if(str[0] == '>')       return G_LEX;
    if(str == ">=")         return GE_LEX;
    if(str == "==")         return EQ_LEX;
    if(str == "!=")         return NEQ_LEX;

    if(str == "dq")         return DQ_LEX;
    if(str == "dw")         return DW_LEX;
    if(str == "dd")         return DD_LEX;
    if(str == "db")         return DB_LEX;

    if(std::isdigit(str[0]))    return NUMBER_LEX;
    if(is_reg_name(str))          return REG_NAME_LEX;

    return UNDEFINE_LEX;
}

bool
NASMPPLexer::is_spec(char c){
    return 
        c == '!' ||
        c == '(' ||
        c == ')' ||
        c == '[' ||
        c == ']' ||
        c == '{' ||
        c == '}' ||
        c == '=' ||
        c == ',' ||
        c == ':' ||
        c == '+' ||
        c == '-' ||
        c == '<' ||
        c == '>'
    ;
}

bool
NASMPPLexer::is_spec_str(const std::string& str){
    return
        str == "++" ||
        str == "--" ||
        str == "=>" ||
        str == "<=" ||
        str == ">=" ||
        str == "==" ||
        str == "!="
    ;
}

bool
NASMPPLexer::is_spec_str(const s8* str){
    return NASMPPLexer::is_spec_str(std::string(str));
}

bool 
NASMPPLexer::is_reg_name(const std::string& str){
    for(s8 i = 0; i < COUNT_OF_REGISTERS; ++i)
        if(str == registers[i]) return true;

    return false;
}