#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {
	T Dato;
	int clave;
    nodo<T> * sig;
};

template <class T>
class lista{
	nodo <T> *cab;
	int tam;
			
	public: lista(){
		cab = NULL; 
		tam = 0;
	}
	bool clave_existe(int clav);
	bool lista_vacia();
	void insertar(int clav, T info);
	void borrar(int clav);
	T buscar(int clav);
	void cambiar(int clav, T infoNueva);
	void recorrer();
	
	int get_tam(){
		return tam;
	}		
};

template <class T>
bool lista<T>::lista_vacia(){
	if(tam == 0)
		return true;
	else
		return false;	
}

template <class T>
bool lista<T>::clave_existe(int clav){
	/*if(tam >= 1){
		nodo<T> *temp;
		temp = cab;
		std::cout<<"Entro en el ciclo"<<std::endl;
		while(temp->clave != clav && temp->sig != NULL){	
			std::cout<<"Entro en el ciclo"<<std::endl;
			temp = temp->sig;
			if(temp->clave == clav){
				return true;
			}
		}
		return false;	
	}else*/	
		return false;
}


template <class T>
void lista<T>::recorrer(){
    nodo<T>* Aux = cab;
    while (Aux != NULL) {
        cout<<" Nombre: "<<((Aux->Dato).nombre)<<" Codigo: "<<((Aux->Dato).codigo)<<" Clave = "<<((Aux->clave)) <<endl;
        Aux = Aux->sig;
    }
}

template <class T>
T lista<T>::buscar(int clav){
	nodo<T> *temp;
	temp = cab;
	while(temp->clave != clav){	
		temp = temp->sig;
	}
	return temp->Dato;
}


template <class T>
void lista<T>::insertar(int clav, T info){
	if(!clave_existe(clav)){
		if(!lista_vacia()){
			nodo<T> *nuevo, *aux1, *aux2;
			nuevo = new nodo <T>;
			nuevo->Dato = info;
			nuevo->clave = clav;
			aux1 = cab;
			aux2 = cab->sig;
			while(clav > aux1->clave && aux1->sig != NULL){
				aux1 = aux2;
				aux2 = aux1->sig;
			}
			aux1->sig = nuevo;
			nuevo->sig = aux2;
			tam++;		
		}else{
			nodo<T> *cabeza;
			cabeza = new nodo <T>;
			cabeza->Dato = info;
			cabeza->clave = clav;
			cabeza->sig = cab;
			cab = cabeza;
			tam++;
		}
	}else{
		std::cout << "La clave ya existe, no se ingresó ningun dato" << std::endl;
	}	
		
}

#endif
