#ifndef COMMON_H
#define COMMON_H

#include <cstdint>
#include <string>

typedef unsigned char   u8;
typedef char            s8;
typedef unsigned short  u16;
typedef short           s16;
typedef uint32_t        u32;
typedef int32_t         s32;
typedef unsigned long   u64;
typedef long            s64;


#define COUNT_OF_REGISTERS 77
const std::string registers[] 
{
    // 8 bit
    "ah", "al", 
    "bh", "bl", 
    "ch", "cl",
    "dh", "dl",

    // additional 8 bit registers
    "sil", "dil",
    "bpl", "spl",
    "r8b", "r9b",
    "r10b", "r11b",
    "r12b", "r13b",
    "r14b", "r15b",


    // 16 bit
    "ax", "bx",
    "cx", "dx",
    "si", "di",
    "bp", "sp",
    "cs", "ds",
    "es", "ss",
    "fs", "gs",

    // additional 16 bit registers
    "r8w", "r9w",
    "r10w", "r11w",
    "r12w", "r13w",
    "r14w", "r15w",


    // 32 bit
    "eax", "ebx",
    "ecx", "edx",
    "esi", "edi",
    "ebp", "esp",
    "eip", "eflags",

    // additional 32 bit registers
    "r8d", "r9d", 
    "r10d", "r11d",
    "r12d", "r13d",
    "r14d", "r15d",


    // 64 bit
    "rax", "rbx",
    "rcx", "rdx",
    "rsi", "rdi",
    "rbp", "rsp",
    "rip", "rflags",

    // additional 64 bit registers
    "r8", "r9",
    "r10", "r11",
    "r12", "r13",
    "r14", "r15"
};

#endif //COMMON_H