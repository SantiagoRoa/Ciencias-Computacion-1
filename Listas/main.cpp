#include <iostream>
#include <cstdlib>
#include "lista.h"

struct persona{
	string nombre;
	int codigo;
};

int main(int argc, char** argv) {
	int pos = 1;
	
	lista<persona> d;
	persona per;
	
	per.codigo = 1000;
	per.nombre = "Juan";
	d.insertar(10, per);
	
	per.codigo = 1500;
	per.nombre = "Pedro";
	d.insertar(50, per);
	
	per.codigo = 1100;
	per.nombre = "María";
	d.insertar(40, per);
	
	per.codigo = 1200;
	per.nombre = "Ana";
	d.insertar(30, per);
	
	/*while(pos <= d.get_tam()){
		pos++;
	}*/
	
	d.recorrer();
	
	return 0;
}
