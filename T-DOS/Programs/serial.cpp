#include <../T-DOS/Programs/programinc.h>

int sout(const char* str){
    do {
    com1_putc(*(str++));
    } while (*str);
    return 0;
}