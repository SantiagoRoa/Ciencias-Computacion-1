#include <iostream>
#include <unistd.h>
#include <fstream>
#include <chrono>

using namespace std;

void ordenrapido(int [] , int, int );
void intercambio(int [] , int, int );
void llenar (int[],int);
void mostrar (int[],int);

void process_mem_usage(double& vm_usage, double& resident_set)
{
    vm_usage     = 0.0;
    resident_set = 0.0;

    // the two fields we want
    unsigned long vsize;
    long rss;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> vsize >> rss;
    }
    vm_usage = vsize / 1024.0;
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
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



int main() {
	
	double vm;
	double rss;
	
	int N = 0;
	cout<< "Digite el tamaño del arreglo"<<endl;
	cin>>N;
	
	int a[N];
	cout<<"Digite el valor de cada posicion"<<endl;
	
	llenar(a,N);

	auto start = chrono::steady_clock::now();	
	selectionSort(a,N);
	auto end = chrono::steady_clock::now();
	
	double tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	
	cout<<" Arreglo ordenado"<<endl;
	mostrar(a,N);
	
	process_mem_usage(vm, rss);
	cout<<endl<<endl << "Tiempo de ejecucion: " 
	<< tiempo/(1000000)<< " ms " << endl;
	
	
	cout<<"Memoria usada: "<<vm;

	return 0;
}

