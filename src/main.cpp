#include "./lib/dot_h/ErrorHandler.h"
#include "./lib/dot_h/CommandHandler.h"

#define DEFAULT_OTP_FILE_NAME "a.o"

int
main(int argc, char** argv){
    if(argc < 2)
        _abort_w_msg(
            "Too few arguments! Correct use is:\n"
            "nasm++ <input_file(-s)>\n"
            "\tor\n"
            "nasm++ <input_file(-s)> -o <output_file>", // exit message
            
            1 // exit code
        );


    std::string cmd_words[argc];

    for(int i = 0; i < argc; ++i)
        cmd_words[i] = std::string(argv[i]);

    int
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

    return 0;
}