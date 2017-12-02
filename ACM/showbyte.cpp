#include <cstdio>
#include <cstring>
//#include <cmath>
//#include <iostream>
//#include <windows.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len){
	for (size_t i = 0; i<len; i++){
		printf(" %.2x",start[len-1-i]);
	}
	printf("\n");
}
int main(){
	int x = 0x12345678; 
	show_bytes((byte_pointer)&x,4); 
	//printf("%hhu",ux);
	return 0;
}

