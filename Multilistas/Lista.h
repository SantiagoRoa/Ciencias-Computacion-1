#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T Dato;
    nodo<T>* sig;
};

template <class T>
class lista {
    nodo<T>* cab;
    int tam;

public:
    lista()
    {
        cab = NULL;
        tam = 0;
    }
    bool lista_vacia();
    void insertar(T info);
    void imprimir();
    bool borrar(int pos);
    bool buscar(int pos);
    
    
};



template <class T>
bool lista<T>::lista_vacia()
{
    if (cab == NULL)
        return true;
    else
        return false;
}


template <class T>
void lista<T>::insertar(T info)
{

    nodo<T> *nuevo, *aux = cab;
    nuevo = new nodo<T>;
    nuevo->Dato = info;
    
    nuevo->sig = NULL;
    
    if (cab == NULL) {
        cab = nuevo;
         
    }
    else {
    	
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    tam++;
    
    

}

template <class T>
bool lista<T>::borrar(int pos)
{
    if (tam >= pos) {
        nodo<T>* temp;
        temp = cab;
        if (pos == 1) {
            cab = temp->sig;
            delete temp;
        }
        else {
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->sig;
            }
            nodo<T>* aux;
            aux = temp->sig;
            temp->sig = aux->sig;
            delete aux;
        }
        tam--;
        return true;
    }
    else
        return false;
}





template <class T>
void lista<T>::imprimir(){
	nodo<T> *aux = cab;
	while (aux!= NULL) {
		cout<< aux->Dato.nombre<<" "<<endl;
		
		aux = aux->sig;
    }	
}

template <class T>
bool lista<T>::buscar(int pos)
{
    nodo<T>* aux = cab;
    int p = 1;
    if (pos <= tam) {
        while (p < pos && aux != NULL) {
            aux = aux->sig;
            p++;
        }
        
        return true;
    }
    return false;
}


/*



template <class T>
bool lista<T>::cambiar(int pos, T infoNueva)
{
    nodo<T>* aux = cab;
    int p = 1;
    if (pos <= tam) {
        while (p < pos && aux != NULL) {
            aux = aux->sig;
            p++;
        }
        aux->Dato = infoNueva;
        return true;
    }
    return false;
}
*/
#endif
