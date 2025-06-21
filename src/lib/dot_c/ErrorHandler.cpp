#include "../dot_h/ErrorHandler.h"

[[noreturn]] void
_abort(const s32 code){
    exit(code);
}

[[noreturn]] void
_abort_w_msg(const s8* msg, const s32 code){
    std::cout << msg << std::endl;
    _abort(code);
}