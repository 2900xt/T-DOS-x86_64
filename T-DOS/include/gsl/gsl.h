#ifndef gsl_H
#define gsl_H

#include <globl.h>
#include <gsl/io.h>


namespace gsl{
    class string{

    public:
        char* data;

        string(const char* str){
            data = (char*)calloc(strlen(str));
            strcpy(data,str);
        }
        string(){
            data = NEW(char);
        }
        ~string(){
            free(data);
        }
        bool operator==(const char* str){
            return stringCmp(str,this->c_str());
        }
        bool operator==(string& str){
            return stringCmp(str.c_str(),this->c_str());
        }
        void operator=(const char* str){
            strcpy(data,str);
        }
        void operator=(string str){
            strcpy(data,str.c_str());
        }
        char* c_str(){
            return data;
        }
    };

    class sstring : public string{
    public:
    
        sstring(const char* str){
            data = (char*)calloc(strlen(str));
            strcpy(data,str);
        }
        sstring(){
            data = NEW(char);
        }
        ~sstring(){
            free(data);
        }

        void operator<<(const char* str){
            data = (char*)realloc(data,strlen(str));
            strcat(data,str);
        }
        void operator<<(string& str){
            data = (char*)realloc(data,strlen(str.c_str()));
            strcat(data,str.c_str());
        }
        void operator>>(string& str){
            str = data;
            return;
        }
    };
}

#endif