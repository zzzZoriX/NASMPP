#include "../dot_h/CommandHandler.h"

const CmdParseResults
_parse_call_command(const std::string cmd[], const int length, int* const start, int* const end, std::string* otp){
    CmdParseResults result = SUCCES_BUT_WO_OTP;
    
    for(int i = 0; i < length; ++i){
        {
            char ext[5] = {
                cmd[i][cmd[i].length() - 5],
                cmd[i][cmd[i].length() - 4],
                cmd[i][cmd[i].length() - 3],
                cmd[i][cmd[i].length() - 2],
                cmd[i][cmd[i].length() - 1]
            };

            if(!strcmp(ext, "asmpp"))
                *start = i;
            
            else if(i == length || strcmp(ext, "asmpp"))
                *end = i;
        }

        if(cmd[i] == "-o"){
            result = SUCCES;
            *otp = cmd[i];
        }
    }

    return result;
}