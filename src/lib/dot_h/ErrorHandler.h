#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <cstdlib>
#include <iostream>

/**
 * @brief abort program w exit-code from params
 * 
 */
[[noreturn]] void
_abort(const int);

/**
 * @brief print msg and abort program w exit_code from params
 * 
 */
[[noreturn]] void
_abort_w_msg(const char*, const int);

#endif //ERRORHANDLER_H