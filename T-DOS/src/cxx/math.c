#include <globl.h>
#include <gsl/io.h>
int64_t pow(int64_t base, int64_t power){
    int64_t current = base;
    for (int i = 0;i<power;i++){
        current = current * base;
    }
    return current/base;
}
int64_t sqrt(int64_t x){
    int64_t current = 0;
    for (;current!=pow(2,x);current++){
        if (x > 256){
            return 0;
        }
    }
    return current;
}
int charToInt(char c){
  switch (c){
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -1;
  }  
}
int stringToInt(const char* str){
    int length = strlen(str);
    int out = 0;
    for (int i = 0;i<length;i++){
        out = pow(10,length-i)*charToInt(str[i]);
    }
    return out;
}
void mkRow(char c){
    g_ScreenX = 0;
    for (int i = 0;i<80;i++){
        putc(c);
    }
}
const char* subStr(const char* str, int start, int finish){
    char* out = NEW(char);
    for(int i = start;i<finish;i++){
        out[i-start] = str[i];
    }
    return out;
}
void calculate(){
    
        switch(ProgramBuffer[PBC-2]){
            case '-':
                cout("%d\n",(charToInt(ProgramBuffer[PBC-3]))-(charToInt(ProgramBuffer[PBC-1])));
                return;
        }
    
    cout("Syntax Error!\n");
    mkRow('_');
    return;
}
