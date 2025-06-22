#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "Common.h"

#include <cstdlib>
#include <iostream>

/**
 * @brief abort program w exit-code from params
 * 
 */
[[noreturn]] void
_abort(const s32);

/**
 * @brief print msg and abort program w exit_code from params
 * 
 */
[[noreturn]] void
_abort_w_msg(const s8*, const s32);

[[noreturn]] void
_abort_w_msg(const std::string&, const s32);

#endif //ERRORHANDLER_H