#include <cstdio>
#include <cstring>
//#include <cmath>
//#include <iostream>
//#include <windows.h>
bool tadd_ok(int x, int y)
{
	int s = x + y;
	if (x>0 && y>0)
		return s>0;
	if (x<0 && y<0)
		return s<0;
	return 1;
}
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%hhu", tadd_ok(x,y)?1:0);
	return 0;
}

