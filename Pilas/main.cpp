#include <iostream>
#include <cstdlib>
#include "pilas.h"

using namespace std;

int main(){
	char c; 
	Pila acc; 
	int x;
		while(cin.get(c)){	
		x = 0;
		while (c == ' ')
			cin.get(c); 
		while(c >= '0' && c <= '9'){
			cout << "entra";
			x = 10 * x + (c - '0');
		cin.get(c);
		}
		if (c == '+')
			x = acc.pop() + acc.pop();
		if (c== '*')
			x = acc.pop() * acc.pop();
		acc.push(x);
	}
	cout << acc.pop() << '\n';
	cout << '\n';

}
