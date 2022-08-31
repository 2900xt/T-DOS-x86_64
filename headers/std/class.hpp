#pragma once
#include <mem/heap.h>
#include <std/io.hpp>
#include <stdarg.h>
void cout(const char* fmt, ...);

char* my_strcat(char* destination, const char* source);
char* strcpy(char* destination, const char* source);




namespace gsl{
    template <class T>
    class Array{
        T* ptr = nullptr;
        uint16_t size = 0;

    public:
        Array(){
            ptr = (T*)(calloc(sizeof(T)));
            size++;
        }
        Array(T* input){
            ptr = (T*)(calloc(sizeof(input)));
            for (int i=0;i<sizeof(input);i++){
                ptr[i] = input[i];
                size++;
            }
        }
        T operator[](uint16_t index){ 
            return ptr[index];
        }
        T* data(){
            return ptr;
        }
    };
    
    class String{

        char* data = nullptr;
        uint16_t size = 0;

    public:
        String(char* input){
            data = (char*)calloc(sizeof(input));
            for (int i=0;i<sizeof(input);i++){
                data[i] = input[i];
                size++;
            }
        }
        String(){
            data = (char*)calloc(sizeof(char));
            size++;
        }
        char* c_str(){
            return data;
        }
        char operator[](uint16_t index){
            return data[index];
        }
        void operator<<(const char* str){
            char* auxptr = (char*)realloc(data,size+sizeof(str));
            data = auxptr;
            strcpy(data,my_strcat(data,str));
            return;
        }

        void operator=(const char* str){
            char* auxptr = (char*)realloc(data,size+sizeof(str));
            data = auxptr;
            strcpy(data,str);
            return;
        }
        void print(){
            cout("%s",this->c_str());
        }
    };
}