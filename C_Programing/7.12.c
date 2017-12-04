#include <stdio.h>
int main(){
	float pre,tmp; char _operator;
	printf("Enter an expression:");
	scanf("%f",&pre);
	while ((_operator=getchar())!='\n'){
		scanf("%f",&tmp);
		switch (_operator){
			case '+': pre+=tmp; break;
			case '-': pre-=tmp; break;
			case '*': pre*=tmp; break;
			case '/': pre/=tmp; break;
		}
	}
	printf("Value of expression:%.1f",pre);
	//getchar();
	return 0;
}
