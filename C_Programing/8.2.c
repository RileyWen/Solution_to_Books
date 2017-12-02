#include <stdio.h>
int main(){
	int occur[10]={},i; char num;
	printf("Enter a number:");
	while ((num=getchar())!='\n')
		occur[num-'0']++;
	printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\nOccurrences:\t");
	for (i=0;i<10;i++)
		printf("%d ",occur[i]);
	return 0;
}
