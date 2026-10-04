#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public: 
	void insert(int pos, T e){
	if (pos<0 || pos>size){
		throw std::out_of_range("Fuera del rango");
	}
	data[pos] = e;
	}
	
	void append(T e){
	data[size-1] = e;
	}
	
	void prepend(T e){
	data[size+1-size] = e;
	}
	
	T remove(int pos){
	if (pos<0 || pos>size){
		throw std::out_of_range("Fuera del rango");
	}
	return data[pos];
	delete	
};

#endif
