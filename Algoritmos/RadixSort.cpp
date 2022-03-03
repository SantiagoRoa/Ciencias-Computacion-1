#include<iostream> 
#include <chrono>
using namespace std; 

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

int valorMaximo(int arreglo[], int n) 
{ 
    int maximo = arreglo[0]; 
    for (int i = 1; i < n; i++) 
        if (arreglo[i] > maximo) 
            maximo = arreglo[i]; 
    return maximo; 
} 
  
// Funcion que computa un countSort para arreglo[] 
// dependiendo del digito representado por exp
void countSort(int arreglo[], int n, int exp) 
{ 
    int salida[n]; 
    int i, contador[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        contador[ (arreglo[i]/exp)%10 ]++; 
  
    // Se cambia contador[i]Change count[i] so that count[i] 
    // Contador ahora contiene la posicion real del digito en el arreglo de salida 
    for (i = 1; i < 10; i++) 
        contador[i] += contador[i - 1]; 
  
    // Arreglo de salida
    for (i = n - 1; i >= 0; i--) 
    { 
        salida[contador[ (arreglo[i]/exp)%10 ] - 1] = arreglo[i]; 
        contador[ (arreglo[i]/exp)%10 ]--; 
    } 
  
    // Se copia el arreglo de salida al arreglo[]Copy the output array to arr[] 
    // arreglo[] ahora contiene numeros ordenados, dependiendo del digito actual 
    for (i = 0; i < n; i++) 
        arreglo[i] = salida[i]; 
} 
  
// Radix Sort 
void radixsort(int arreglo[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = valorMaximo(arreglo, n); 
  
    // CountingSort para cada dígito.  exp is 10^i 
    // exp = 10^i 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arreglo, n, exp); 
} 
  
int main() 
{ 
	int n = 0;
	cout<< "Digite el tamaño del arreglo"<<endl;
	cin>>n;
	
	int a[n];
	cout<<"Digite el valor de cada posicion"<<endl;
	
	llenar(a,n);

	auto start = chrono::steady_clock::now();	
	radixsort(a, n); 
	auto end = chrono::steady_clock::now();

	cout<<"Arreglo ordenado [Por residuos]"<<endl;
	mostrar(a,n);
	
	double tiempo =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout<<endl<<endl << "Tiempo de ejecucion: " 
	<< tiempo/(1000000)<< "  ms" << endl;
 
    return 0; 
} 
