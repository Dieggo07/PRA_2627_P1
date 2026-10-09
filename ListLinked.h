#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        ListLinked(){
		first=nullptr;
	}

	~ListLinked(){
		while(first!=nullptr){
			Node<T>* aux=first->next;
			delete[] first;
			first=aux;

	}
	}

	T operator[](int pos){
		if(pos<0 || pos>n-1){
			std::out_of_range("Error. Fuera del rango.");
		}
		return first[pos]; 
	}

	friend std::ostream& operator<<(std::ostream &out, ListLinked &list){
		out << list.data;

		return out;
	}
};


#endif 
