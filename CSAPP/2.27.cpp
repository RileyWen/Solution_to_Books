#include <cstdio>
#include <cstring>
//#include <cmath>
//#include <iostream>
//#include <windows.h>
bool uadd_ok(unsigned x, unsigned y)
{
	unsigned s = x + y;
	return s<x ? false : true;
}
int main(){
	unsigned x,y;
	scanf("%u%u",&x,&y);
	printf("%hhu", uadd_ok(x,y)?1:0);
	return 0;
}

