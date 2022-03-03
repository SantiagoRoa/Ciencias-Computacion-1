#include <iostream>
#include <chrono>

//ANALISIS DE COMLEJIDAD EN TIEMPO
//ALGORITMOS DE ORDENAMIENTO RECURSIVOS

//Intercambio De Residuos 	

using namespace std;


void cambioresiduos(int [], int , int , int );

void intercambio(int [],int,int);
void llenar (int[],int);
void mostrar (int[],int);

int N;

int main() {
	
	
	cout<< "Digite el tamaño del arreglo"<<endl;
	cin>>N;
	
	int a[N];
	cout<<"Digite el valor de cada posicion"<<endl;
	
	llenar(a,N);

	auto start = chrono::steady_clock::now();	
	cambioresiduos(a,0,N-1,8);
	auto end = chrono::steady_clock::now();


	cout<<" Arreglo ordenado [Intercambio de residuos]"<<endl;
	mostrar(a,N);
	
	double tiempo =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout<<endl<<endl << "Tiempo de ejecucion: " 
	<< tiempo/(1000000)<< "  ms" << endl;
	
	


	return 0;
}


inline unsigned bits (int x, int k, int j){
	
	return (x>>k)&~(~0<<j);
}

void cambioresiduos(int a[], int izq, int der, int b){
	int i,j, t;
	if (der>izq && b>=0){
		i= izq; j=der;
		while(j!=i){
			while((!bits(a[i],b,1))&& i<j)i++;
			while((bits(a[j],b,1) ) && j>i)j--;
			intercambio(a, i, j);
		}
		
		if (!bits(a[i],b,1)) j++;
		cambioresiduos(a, izq, j-1, b-1);
		cambioresiduos(a, j, der, b-1);
	}
}





void intercambio(int a[], int min , int i ){
	int aux;
	aux=a[min];
	a[min]=a[i];
	a[i]=aux;

}

void llenar(int a[], int N ){
	for (int i=0;i<N; i++){
		cin>>a[i];
	}
}


void mostrar (int a[],int N){
	cout << "[";
	for (int i=0;i<N; i++){
    	cout<<" "<<a[i]<<" ";
    }
    cout << "]";	
}
