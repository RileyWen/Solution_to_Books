#include <stdio.h>
int main(){
	char tmp;
	printf("Enter phone number:");
	while ((tmp=getchar())!='\n'){
		tmp = 	(tmp<='Z' && tmp>='A')
				? "22233344455566677778889999"[tmp-'A']
				: tmp; 
		printf("%c",tmp);
	}
	return 0;
} 
