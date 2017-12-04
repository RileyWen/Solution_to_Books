#include <stdio.h>
int main(){
	char tmp[24]={},*p=tmp;int shift;
	printf("Enter message to be encrypted: ");
	gets(tmp);
	printf("Enter shift amount: ");
	scanf("%d",&shift);
	do{
		if (*p>='A' && *p<='Z') *p=(*p-'A'+shift)%26+'A';
		if (*p>='a' && *p<='z') *p=(*p-'a'+shift)%26+'a';
	}while (*++p);
	printf("Encrypted message: %s",tmp);
	return 0;
}
