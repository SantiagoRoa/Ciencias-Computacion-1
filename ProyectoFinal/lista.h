#ifndef LISTA_H
#define LISTA_H
#include <iostream>

//UNIVERSIDAD DISTRITAL
//LISTAS CON CLAVES

using namespace std;

template <class T>
struct nodo {
    int id;
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
    
    void imprimirProfesor();
    T buscarSinClave(int pos);
    bool lista_vacia();
    void insertar(T info,int clave);
    void insertarSinClave(T info);
    bool borrar(int clave);
    T buscar(int clave);	
    bool modificar(int clave, T infoNueva);
    bool comprobar_clave(int clave);
    void recorrerCorte();
    void recorrerEvaluacion();
    void destructor();
    bool borrarSinClave(int pos);
    void imprimirTema();
    int get_tam()
    {
        return tam;
    }
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
void lista<T>::insertar(T info, int clave)
{

    if (comprobar_clave(clave)) {
        
    }
    else if (!lista_vacia()) {
    
        nodo<T> *nuevo, *Aux, *Aux2;
        nuevo = new nodo<T>;
        nuevo->Dato = info;
        nuevo->id = clave;
        Aux = cab;
        Aux2 = cab;

        while ((Aux!= NULL) && (Aux->id < clave)) {
         
            Aux2 = Aux;
            Aux = Aux->sig;
           
        }
        
        if(Aux==cab){
        	cab=nuevo;
        	nuevo->sig = Aux;
        	
		}else{
			Aux2->sig = nuevo;
        	nuevo->sig = Aux;
        
		}
     
        
    }else {
    	nodo<T> *nuevo, *Aux, *Aux2;
        nuevo = new nodo<T>;
        nuevo->Dato = info;
        nuevo->id = clave;
        nuevo->sig=cab;
        cab=nuevo;
     
    }
    tam++;
    
}



template <class T>
void lista<T>::insertarSinClave(T info)
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
T lista<T>::buscarSinClave(int pos)
{   nodo <T> *aux=cab;
    int p = 1;
    if (pos<=tam)
       { while(p<pos && aux != NULL)
            {aux = aux->sig;
                p++;
            }
        return aux->Dato;
        }
}


template <class T>
void lista<T>::destructor()
{
    nodo<T> *aux=cab;
    
    while (aux != NULL) {
    	cab = aux;
        aux = aux->sig;
        delete cab;
    }
    cab=NULL;
    
}

template <class T>
bool lista<T>::borrar(int clave)
{
    if (comprobar_clave(clave)) {
        nodo<T>*Aux = cab, *Aux2;

        
        while ((Aux->id)!=clave && Aux != NULL) {
        	Aux2 = Aux;
            Aux = Aux->sig; 
        }
        
        Aux2->sig=Aux->sig;
        delete Aux;
        return true;
    }
    else
        return false;
}

template <class T>
T lista<T>::buscar(int clave)
{
	nodo<T>* Aux = cab;
    
    if (comprobar_clave(clave)) {
        while ((Aux->id)!=clave && Aux != NULL) {
            Aux = Aux->sig;
        }
         
        return Aux->Dato;
    }
}

template <class T>
bool lista<T>::comprobar_clave(int clave)
{
    nodo<T>* aux = cab;
    
    while (aux != NULL) {
        if (aux->id == clave) {
            return true;
        }
        
        aux = aux->sig;
    }
    return false;
}

template <class T>
bool lista<T>::modificar(int clave, T infoNueva)
{
    nodo<T>* Aux = cab;
    
    if (comprobar_clave(clave)) {
        while ((Aux->id)!=clave && Aux != NULL) {
            Aux = Aux->sig;
        }
        Aux->Dato = infoNueva;
        return true;
    }
    return false;
}

template <class T>
void lista<T>::imprimirProfesor(){
	nodo<T> *aux = cab;
	int i = 0;
	cout<<" #    Cédula    Nombre    Apellido    No. Clases"<<endl<<endl;
	while (aux!= NULL) {
		i++;
		cout<<" "<<i<<".   "<<aux->Dato.cedula<<"    "<<aux->Dato.nombre<<"      "<<aux->Dato.apellido<<"         "<<aux->Dato.numClases<<endl;
		cout<<endl;
		aux = aux->sig;
    }	
}

/*template<class T>
int lista<T>::getCedulas(int pos){
	nodo<T> *aux = cab;
	int p = 0;
	while (aux!= NULL && p < pos) {
		aux = aux->sig;
    	p++;
	}
	return aux->Dato.cedula;
}*/

template <class T>
void lista<T>::recorrerCorte()
{
	int numCorte=0;
	
 	nodo<T> *aux = cab;
 	 
	while (aux!= NULL) {
		
		cout<<" Corte "<<numCorte + 1<<"-----------------"<<endl;
		
		  for(int j =0; j<10;j++){
                cout<<endl<<" Nota "<<j+1<<endl;
                cout<<" Tipo: "<<(aux->Dato).notas[j].Tipoevaluacion<<endl;
                cout<<" "<<(aux->Dato).notas[j].porcentaje<<"% \n"<<endl;
            	if((aux->Dato).notas[j+1].porcentaje == 0)
            		j = 10;
			}
        numCorte++;
		aux = aux->sig;
    }	        

}

template <class T>
bool lista<T>::borrarSinClave(int pos)
{ if(tam >= pos)
     { nodo <T> *temp;
       temp = cab;
       if(pos == 1)
         {cab = temp->sig;
          delete temp;
         }
       else
         {for(int i=1;i<pos-1;i++)
             {temp = temp->sig;}          
          nodo <T> *aux;
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
void lista<T>::recorrerEvaluacion(){
 	nodo<T> *aux = cab;
 	int j = 1;
	while (aux!= NULL) {
		cout<<" 	Punto "<< j <<": "<<(aux->Dato).porcentajePunto<<"%  Tema "<< (aux->Dato).CodigoTema<<endl;
		aux = aux->sig;
		j++;
    }		
}


template <class T>
void lista<T>::imprimirTema(){
	nodo<T> *aux = cab;
	int i = 0;
	cout<<" #  codigo    Nombre    "<<endl<<endl;
	while (aux!= NULL) {
		i++;
		cout<<" "<<i<<".   "<<aux->Dato.codigo<<"    "<<aux->Dato.nombre<<"      "<<endl;
		cout<<endl;
		aux = aux->sig;
    }	
}
#endif
