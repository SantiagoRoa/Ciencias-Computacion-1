#ifndef PILAS_H
#define PILAS_H

#include <iostream> 

using namespace std;

class Pila{
	
	public:
		Pila ();
   		~Pila();
    	void push(int V);
    	int pop();
    	int vacia();
    	
	private:
		struct nodo{
			int clave; 
			nodo *siguiente;
		};
		nodo *cabeza, *z;
 };

Pila::Pila(){ 
	cabeza = new nodo;  
	z = new nodo;
	cabeza->siguiente = z; 
	z -> siguiente = z;
}

Pila::~Pila(){
	nodo *t = cabeza;
	while (t!=z){
		cabeza = t;  
		t = t->siguiente;
		delete cabeza;
	}
	delete z;
}

void Pila::push(int v){
	nodo *t = new nodo;
	t->clave = v;  
	t->siguiente = cabeza->siguiente;
	cabeza->siguiente = t;
}

int Pila::pop(){
	int x;
	nodo *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente; 
	x = t->clave;
	delete t; 
	return x;
}

int Pila::vacia(){
	return cabeza->siguiente == z;
	}

#endif
