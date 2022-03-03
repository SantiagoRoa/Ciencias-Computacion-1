#include <cstdlib>
#include <iostream>
#include <locale.h>
#include "monticulo.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");

	monticulo myMonticulo(6);
	
	myMonticulo.push(15);
	myMonticulo.push(2);
	myMonticulo.push(43);
	myMonticulo.push(35);
	myMonticulo.push(12);
	myMonticulo.push(9);
	
	myMonticulo.printArray();
	
	myMonticulo.pop();
	
	std::cout<<std::endl<<"Después de atender la cola: "<<std::endl<<std::endl;
	myMonticulo.printArray();
}
