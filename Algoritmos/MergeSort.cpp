#include <iostream>
#include <chrono>

using namespace std;


void MergeSort(int[],int,int );
void MergeLists( int [],int,int,int,int );
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
	MergeSort(a,0,N-1);
	auto end = chrono::steady_clock::now();


	cout<<" Arreglo ordenado [MergeSort]"<<endl;
	mostrar(a,N);
	
	double tiempo =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout<<endl<<endl << "Tiempo de ejecucion: " 
	<< tiempo/(1000000)<< "  ms" << endl;
	
	


	return 0;
}


void MergeSort( int a[], int first,int last ){
	int middle;
	if (first < last){
		middle = ( first + last ) / 2;
		MergeSort( a, first, middle );
		MergeSort( a, middle + 1, last );
		MergeLists( a, first, middle, middle + 1, last );
	}
}

void MergeLists( int a[], int start1,int end1,int start2,int end2 ){
	int i=0 ,finalStart=0, finalEnd=0, indexC=0;
	int result[N];
	
	finalStart = start1;
	finalEnd = end2;	
	indexC = 1;
	while ((start1 <= end1) && (start2 <= end2)) {
	
		if (a[start1] < a[start2] ){
		
			result[indexC] = a[start1];
			start1 = start1 + 1;
			
		}
		else
		{
				
				result[indexC] = a[start2];
				start2 = start2 + 1;
		}
			
		
		indexC = indexC + 1;
	}
	
	if (start1 <=end1) {
		for (i = start1;i<=end1;i++) {
			
			result[indexC] = a[i];
			indexC = indexC + 1;
			
		}
		
	}
	else
	{
		
		for (i = start2 ;i<=end2;i++ ){
			result[indexC] = a[i];
			indexC = indexC + 1;
		
		}
			
	}
	
	indexC = 1;
	for (i = finalStart ;i <=finalEnd;i++) {
		a[i] = result[indexC];
		indexC = indexC + 1;
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

