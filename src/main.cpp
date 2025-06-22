#include "./lib/dot_h/ErrorHandler.h"
#include "./lib/dot_h/CommandHandler.h"
#include "./lib/dot_h/Common.h"
#include "./lib/dot_h/Lexer.h"
#include "./lib/dot_h/Debug.h"

#define DEFAULT_OTP_FILE_NAME "a.o"
#define DEBUG

s32
main(s32 argc, s8** argv){
    if(argc < 2)
        _abort_w_msg(
            "Too few arguments! Correct use is:\n"
            "nasm++ <input_file(-s)>\n"
            "\tor\n"
            "nasm++ <input_file(-s)> -o <output_file>", // exit message
            
            1 // exit code
        );


    std::string cmd_words[argc];

    for(s32 i = 0; i < argc; ++i)
        cmd_words[i] = std::string(argv[i]);

    s32
        start_inp_files = 0,
        end_inp_files = 0
    ;
    std::string output_file_name = DEFAULT_OTP_FILE_NAME;

    _parse_call_command(
        cmd_words,
        argc,
        &start_inp_files, &end_inp_files,
        &output_file_name
    );

    for(s32 i = start_inp_files; i < end_inp_files; ++i){
        std::ifstream input_file(argv[i]);

        NASMPPLexer::Token* tokens = NASMPPLexer::Lexer(input_file);

#ifdef DEBUG
        DEBUG_PRINT_TOKENS(tokens);
#endif
    }

    return 0;
}