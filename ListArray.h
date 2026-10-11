#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

        private:
                T* arr;
                int max;
                int n;
                static const int MINSIZE = 2;
                void resize (int new_size){
                        T* new_arr = new T[new_size];
                        for (int i=0; i<n; i++){
                                new_arr[i] = arr[i];
                        }

                        delete[] arr;
                        max = new_size;
                        arr = new_arr;
                }
        public:
                ListArray(){
                        max = MINSIZE;
                        n = 0;
                        arr = new T[max];
                }
                ~ListArray() override{
                        delete[] arr;
                }
                T operator[](int pos) {
                        if (pos<0 || pos>=n){
                                throw std::out_of_range("Error. Fuera del rango.");
                }
                        return arr[pos];
                }
                friend std::ostream& operator<<(std::ostream& out, ListArray<T>& list){
                        for (int i=0; i<list.n; i++){
                                out << list.arr[i] << " ";
                }
                        return out;
                }

                void insert(int pos, T e){
                        if(pos<0 || pos>n){
                                throw std::out_of_range("Error. Fuera del rango.");
                }
                        if(n==max){
                                resize(max*2);
                }
                        for (int i=n; i>pos; i--){
                                arr[i]=arr[i-1];
                }
                        arr[pos] = e;
                        n++;
                }
                void append(T e){
                        insert (n,e);
                }

                int size(){
                        return n;
                }

                bool empty(){
                        if (n==0){
                        return true;
                        }
                        return false;
                }

                int search(T e){
                        for (int i=0; i<n; i++){
                                if(arr[i] == e){
                                return i;
                }
                }
                        return -1;
                }

                T get(int pos){
                        if(pos<0 || pos>=n){
                                throw std::out_of_range("Error. Fuera del rango.");
                }
                        return arr[pos];
                }

                T remove(int pos){
                        if(pos<0 || pos>=n){
                                throw std::out_of_range("Error. Fuera del rango.");
                }
                        T element=arr[pos];

                        for (int i=pos; i<n-1; i++){
                                arr[i]=arr[i+1];
                        }

                        n--;
                        delete element;
                }

                void prepend(T e){
                        insert(0, e);
                }
};

#endif
