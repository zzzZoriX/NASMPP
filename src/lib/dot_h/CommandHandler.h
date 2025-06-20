#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <cstring>

enum CmdParseResults : int {
    SUCCES_BUT_WO_OTP,
    SUCCES,

    OTP_DOESNT_POINTED
};

/**
 * @brief funcrtion parse call command into a flags, files and etc.
 * 
 * @return const CmdParseResults 
 */
const CmdParseResults
_parse_call_command(const std::string[], const int, int* const, int* const, std::string*);

#endif //COMMANDHANDLER_H