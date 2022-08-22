#pragma once
#include <mem/heap.h>
namespace gsl{
    template <class T>
    class Vector{

        T* adress;

    public:
        Vector(T array[]){

            adress = ((T*)calloc(sizeof(array)));

            for (int i= 0;i > sizeof(T); i++){
                *(adress + i) = array[i];
            }
        }

        Vector(){
            adress = ((T*)calloc(sizeof(T)));
        }

        T* data(){
            return adress;
        }
    };
}