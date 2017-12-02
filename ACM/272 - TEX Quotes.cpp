#include <cstdio>
int main(){
	bool flag=1;
	char c;
	while ((c=getchar())!=EOF){
		if (c=='"'){
			printf("%s",flag?"``":"''");
			flag=!flag;
		}
		else
			printf("%c",c);
	}
	return 0;
}
