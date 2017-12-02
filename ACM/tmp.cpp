#include <cstdio>
#define sign(x) STR_##x
#define STR_i 6
#define STR_1 1
#define STR_2 2
#define STR_3 3
#define STR_4 4
#define STR_5 5
int size(int a[]){
	printf("size:%lld",a[1]);
} 
int main(){
	int d[6]={1,2,3,4,5,6};
	//size(d);
	//printf("size:%lld\n",sizeof(d));
	int a=0xfffffffa;
	printf("%d",a);
	//signed char a = -128;
	//printf("%hhd",a-1);
	return 0;
}
