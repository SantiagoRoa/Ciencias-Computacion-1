#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Lista.h"

using namespace std;

struct ingrediente{
    string nombre;
    string cantidad;
};

struct postre {
    string nombre;
    lista<ingrediente> l_ingre;
};



int main(){
	
	
	lista <postre> recetas;
	
	postre emp,chu,gel;
	ingrediente B;
	
	
	emp.nombre="empanada";
	B.nombre="aji";
	B.cantidad="3 cucharadas";
	emp.l_ingre.insertar(B);
	B.nombre="Masa";
	B.cantidad="20gr";
	emp.l_ingre.insertar(B);
	B.nombre="carne";
	B.cantidad="8gr";
	emp.l_ingre.insertar(B);
	recetas.insertar(emp);


	chu.nombre="churros";	
	B.nombre="masa";
	B.cantidad="30g";
	chu.l_ingre.insertar(B);
	B.nombre="azucar";
	B.cantidad="10g";
	chu.l_ingre.insertar(B);
	recetas.insertar(chu);
	
	
	gel.nombre="gelatina";	
	B.nombre="agua";
	B.cantidad="10ml";
	gel.l_ingre.insertar(B);
	B.nombre="polvo de gelatina";
	B.cantidad="20gr";
	gel.l_ingre.insertar(B);
	recetas.insertar(gel);
	
	
	
	cout<<"los postres que se encuentran son: "<<endl;
	recetas.imprimir();
	cout<<endl;
	cout<<"los ingredietes de churro son: "<<endl;
	chu.l_ingre.imprimir();
	cout<<endl;
	cout<<"los ingredietes de empanada son: "<<endl;
	emp.l_ingre.imprimir();
	cout<<endl;
	cout<<"los ingredietes de gelatina son: "<<endl;
	gel.l_ingre.imprimir();
	cout<<endl;
	
	
	recetas.borrar(2);
	cout<<"los postres que se encuentran (elimando el de la posicion 2 )son: "<<endl;
	recetas.imprimir();
	cout<<endl<<endl;
	
	cout<<"Eliminando un ingrediente de empanada  (el de la primera posicion)"<<endl;
	emp.l_ingre.borrar(1);
	emp.l_ingre.imprimir();

	return 0;
}
