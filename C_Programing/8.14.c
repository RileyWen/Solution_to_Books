#include <stdio.h>
int main(){
	char buf[1000]={},tmp;int j=0,i;
	gets(&buf[1]);
	while (buf[++j]!=46&&buf[j]!=33&&buf[j]!=63){}
	buf[j]^=tmp=buf[j];
	for (i=j; (i--)?1:(!printf("%c",tmp))  ;)
		if ( buf[i]==32?( !(buf[i]^=buf[i]) ):!buf[i] )
			printf( i?"%s ":"%s" ,&buf[i+1]);
	return 0;
}
