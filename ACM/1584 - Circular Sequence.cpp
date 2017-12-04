#include <cstdio>
#include <cstring>
//#include <iostream>
//using namespace std;
void cmp(char* s){
	char minimum[1000];
	bool flag_bigger=false;
	strcpy(minimum,s);
	int len=(int)strlen(s); 
	//cout<<len;
	for (int i=1;i<=len;i++){
		flag_bigger=false;
		for (int j=0;j<len;j++){
			if (minimum[j]!=s[(i+j)%len]){
				if (minimum[j]>s[(i+j)%len]){
					flag_bigger=true;
					break;
				}
				else break;
			}
		}
		if (flag_bigger)
			for (int j=0;j<len;j++){
				//cout<<"j:"<<j<<'\n';
				//cout<<s[(i+j)%len];
				minimum[j]=s[(i+j)%len];
			}
		//cout<<endl;
	}
	printf("%s\n",minimum);
}
int main(){
	int n;
	char s[1000];
	scanf("%d",&n);
	while (n--){
		scanf("%s",s);
		cmp(s);
		} 
	return 0;
}
