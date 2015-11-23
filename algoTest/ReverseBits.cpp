#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint32_t;
uint32_t swapBits(uint32_t n, int i, int j){
	int a = (n >> i) & 1;
	int b = (n >> j) & 1;
	if((a ^ b)){
		n ^= (a<<j | b<<i);
	}
	return n;
}
int main(){
	uint32_t n = 1;
	for(int i=0; i<16; i++){
		n = swapBits(n, i, 32-i-1);
	}
	return 0;
}