#include "../dot_h/ErrorHandler.h"

[[noreturn]] void
_abort(const int code){
    exit(code);
}

[[noreturn]] void
_abort_w_msg(const char* msg, const int code){
    std::cout << msg << std::endl;
    _abort(code);
}