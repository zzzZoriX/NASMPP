#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "Common.h"

#include <string>
#include <cstring>

enum CmdParseResults : s32 {
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
_parse_call_command(const std::string[], const s32, s32* const, s32* const, std::string*);

#endif //COMMANDHANDLER_H