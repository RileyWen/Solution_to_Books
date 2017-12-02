#include <cstdio>
#include <cstring>
#include <cmath>
int main(){
	char s[1000];
	int len_exp,index=2,E[10][31];
	double mantissa=0,lgx,M[10][31];
	int exponent=0;
	for (int m=0;m<=9;m++)
		for (int e=1;e<=30;e++){
			mantissa=double(1)-double(1)/double(1<<(m+1));
			exponent=(1<<e)-1;
			lgx=log10(mantissa)+log10(double(2))*exponent;
			E[m][e]=int(floor(lgx));
			M[m][e]=pow(10,lgx-E[m][e]);
		}
	while (1){
		index=0;mantissa=0;exponent=0;
		memset(s,'\0',sizeof(s));
		
		scanf("%s",s);
		if (s[0]=='0'&&s[1]=='e'&&s[2]=='0') break;
		*(strchr(s,'e'))=' ';
		sscanf(s,"%lf %d",&mantissa,&exponent);
		for (int m=0;m<=9;m++)
			for (int e=1;e<=30;e++){
				if (E[m][e]==exponent&&fabs(M[m][e]-mantissa)<0.00001){
					printf("%d %d\n",m,e);
					goto aaaa;
				}
		}
		aaaa:;
	}
	return 0;
}

