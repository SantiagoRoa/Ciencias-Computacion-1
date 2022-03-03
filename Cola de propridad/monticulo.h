#ifndef MONTICULO_H
#define MONTICULO_H
#include <iostream>

class monticulo{
	
	int *array, size, currentPos, totalSize;

	public: 
		monticulo(int);
		~monticulo();
		bool push(int);
		int pop();
		void printArray();
		bool isFull();
		int get_tam(){
			return size;
		}
		
};

monticulo::monticulo(int _size){
	size = 0;
	currentPos = 1;
	array = new int[_size+1];
	totalSize = _size;
}

monticulo::~monticulo(){
	delete array;
}

bool monticulo::push(int pr){
	int aux;
	if (isFull()){ 
		std::cout<<"La cola está llena"<<std::endl;
		return false;
	}else{
		array[currentPos] = pr;
		size = size + 1;
		int i = currentPos, divisor = 2;
		currentPos++;
		while((i != 1) &&  (array[i] > array[(i/divisor)])){
			aux = array[i];
			array[i] = array[i/divisor];
			array[i/divisor] = aux;
			i = i/divisor;
		}
		return true;
	}
}

int monticulo::pop(){
	int aux, root = 0;
	if (size == 0) { 
		std::cout<<"La cola está vacía"<<std::endl;
	}else{
		root = array[1];
		size = size - 1;
		currentPos--;
		bool end = false; 
		int i = 1;
		while ((2*i >= currentPos) && !end ){  
			if ((2*i+1 >= currentPos) && array[2*i+1] > array[2*i] ){ 
				currentPos = 2*i+1;
			}else{
				currentPos = 2*i;
			}
			if (array[currentPos] > array[i]) { 
				aux = array[i];
				array[i]  =  array[currentPos];
				array[currentPos]  =  aux; 
				i = currentPos;
			}else{
				end = true;
			}
		
		}
	}
	return root;	
}

void monticulo::printArray(){
	for (int i=1;i<currentPos;i++){
		if(array[i]==0)
			std::cout<<"Posición "<<i<<" -> Vacío"<<std::endl;
		else
			std::cout<<"Posición "<<i<<" -> "<<array[i]<<std::endl;
	}
}

bool monticulo::isFull(){
	if (size == totalSize) { 
		return true;
	}else{
		return false;
	}
}

#endif
