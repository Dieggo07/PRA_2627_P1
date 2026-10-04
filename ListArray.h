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
			delete arr;
		}
		T operator[](int pos) {
			if (pos<0 || pos>n-1){
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
	};
