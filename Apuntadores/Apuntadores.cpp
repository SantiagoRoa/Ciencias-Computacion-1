#include <iostream>

//APUNTADORES 
//Christian Isaac Gamboa Restrepo

using namespace std ;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Apuntadores y Desreferenciacion (obtencion de valores que estan en la direccion guardada en dicho apuntador)
void ejemplo_A (){
	
	int x=17,y;
	int *p,*q;
	p=&x;
	q=p;
	cout << "Valor ="<<*q<<" Direccion = "<< q <<endl;
	y=*p+3;
	cout << "Suma  *p + 3 = "<<y<<endl;
	
} 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Apuntadores A Apuntadores (apuntadores que estan ligados a direcciones las cuales guardan otras direcciones ...)
void ejemplo_B (){
	char c='z';
	char *pc=&c;
	char **ppc=&pc;
	char ***pppc=&ppc;
	
	//pc es un apuntador el cual me guarda la direccion de la variable C , si vemos *pc nos muestra lo que guarda la variable a la cual pertenece dicha direccion que es una 'Z' y solo pc sera la direccion de la vaiable C
	cout<<" pc = "<<pc<<endl;
	cout<<" *pc = "<<*pc<<endl;
	cout<<endl<<endl<<endl;
	//**ppc es un doble apuntador, esto significa que es un apuntador que guarda otro apuntador, entiendalo como una direccion la cual me guarda otra direccion 
	
	cout<< " ppc = "<<ppc<<endl;//me muestra la direccion donde se guarda  pc
	cout<< " *ppc = "<<*ppc<<endl;//me muestra lo que guarda la variable ligada a la direccion que guarda  ppc, en este caso mostrar la direccion de la varible C
	cout<< " **ppc = "<<**ppc<<endl;//muestra ahora lo que guarda C que es 'Z'
	cout<<endl<<endl<<endl;
	
	cout<< " pppc = "<<pppc<<endl;//la direccion de ppc 
	cout<< " *pppc = "<<*pppc<<endl;//lo que guarda la direccion de ppc , en este caso la direccion de pc
	cout<< " **pppc = "<<**pppc<<endl;//direccion de la variable C
	cout<< " ***pppc = "<<***pppc<<endl;//lo que guarda la direccion de C que es una 'Z'
	cout<<endl<<endl<<endl;

	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Apuntadores y Arreglos 

//recordar que una matriz es un doble apuntador y un arreglo ya de por si es un apuntador

void arreglo(int *p){
	int i;
	for (i=0; i<10; i++)
	p[i]=i*2;
}
 
void ejemplo_C (){
	
	int i, a[10], *pa, **ppa;
	//inicializamos el arreglo con 0
	for (i=0; i<10; i++)
		a[i]=0;
		
		
	pa=a; // esto se permite por que ambos son apuntadores, en este caso pa ahora guardara la dirrecion que tenia guardada 'a' , que en el caso de los arreglos guarda la direccion del primer termino del arreglo
	
	//ahora me imprime todo lo que habia en el arreglo, que inicialmente eran 0
	for (i=0; i<10; i++)
		cout<< pa[i]<<" ";   // perfectamnete puede verlo como *[pa+i] , solo que la sintaxis de C nos ayuda , aqui podemos concluir que pa siendo un apuntador se puede usra como un arreglo
		
		
	arreglo(pa);
	cout<<endl;
	ppa=&pa;    //dese cuenta que pa ya guarda la direccion de a , entonces ppa ahora guarda la direccion de pa , significa que ppa apunta a una direccion que apunta a potra direccion (por eso es un doble apuntador)
	
	
	//esto ya solo me muestra comoquedo el arreglo despues de pasar por la funcion arreglo
	for (i=0; i<10; i++)
		cout<< *(*ppa+i)<<" ";
	
	cout<<endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------




//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//Apuntadores y matrices
void LlenadoMatriz(int Q[][5]){
	int i, j;
	for(i=0; i<4; i++)
		for(j=0; j<5; j++){
		Q[i][j]= 0;
        }
}

void ejemplo_D(){

int M[4][5], *Pm, i, j;
    Pm= M[0];
    cout<<"M{0} = "<< M[0]<<"  *M = "<< *M <<endl; //esta linea solo es para aclarar conceptos
    LlenadoMatriz(M);
    for(i=0; i<4; i++)
      {for(j=0; j<5; j++)
        {cout<< *Pm << " ";
         Pm=Pm+1;
         }
       cout<<endl;}
       
       cout<<endl;
       
    for(i=0; i<4; i++)
      for(j=0; j<5; j++)
        M[i][j]= i*j;
        
       
    for(i=0; i<4; i++)
      {for(j=0; j<5; j++)
        {cout<< *(*(M+i)+j) << " ";
         }
       cout<<endl;}
            

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------



int main(int argc, char** argv) {
	int op=0;
	bool close = false;
	
	
	while(!close){
		
		
		system("pause");
		system("cls");
		cout << "APUNTADORES"<<endl<<endl<<endl;
		cout << "Escoga el ejemplo que desea ver "<<endl;
		cout << "[1] Desreferenciacion y apuntadores "<<endl;
		cout << "[2] Apuntadores A apuntadores  "<<endl;
		cout << "[3] Apuntadores y arreglos "<<endl;
		cout << "[4] Apuntadores y matrices "<<endl;
		cout << "[5]   "<<endl;
		cout << "[0] Salir"<<endl;
		cout << "Escoga el tema que desea ver "<<endl;
		
		cin>> op;
		
		
		

	
	
		switch(op)
		{
			case 1:
				system("cls");
				ejemplo_A ();
				break;
				
			case 2:
				system("cls");
				ejemplo_B();
				break;
			case 3:
				system("cls");
				ejemplo_C();
				break;
			case 4:
				system("cls");
				ejemplo_D();
				break;
				
			case 0 :
				system("cls");
				close=true;
				break;
		}
	
	}

	return 0;
}
