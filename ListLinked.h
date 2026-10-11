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
		n=0;
	}

	~ListLinked(){
		while(first!=nullptr){
			Node<T>* aux=first;
			first=first->next;
			delete aux;
	}

	}

	T operator[](int pos){
		if(pos<0 || pos>=n){
			std::out_of_range("Error. Fuera del rango.");
		}

		Node<T>* aux = first;

		for (int i=0; i<pos; i++){
			aux = aux->next;
		}

		return aux->data; 
	}

	friend std::ostream& operator<<(std::ostream &out, ListLinked &list){
		Node<T>* aux = list.first;

		while(aux!=nullptr){
			out << aux->data;
		
		if(aux->next != nullptr){
			out << " ";
		}
		
		aux=aux->next;
	}

		return out;
	}
};


#endif 
