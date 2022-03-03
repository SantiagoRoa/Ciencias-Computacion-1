#include <bits/stdc++.h> 
#include <chrono> 
using namespace std; 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){  
    if (n == 1){  
        //std::cout << "1" << " -> " << to_rod << std::endl;  
        return;
    }  
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);  
    //std::cout << n << " -> " << to_rod << std::endl;  
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);  
}  
  
int main(){  
    int n;
	std::cin >> n; 
	auto start = chrono::steady_clock::now();
    towerOfHanoi(n, 'A', 'C', 'B');
    auto end = chrono::steady_clock::now();
	double tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	tiempo /= 1000000;
	std::cout << "t = " << tiempo << " ms" <<std::endl;
	cin >> n;
	return 0;
}  
