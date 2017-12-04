#include <cstdio>
#include <cstring>
//#include <cmath>
//#include <iostream>
int main(){
	char key[8][1<<8],c;
	int index=0,len=1,header_len=0,code_len=0;
	bool key_flag=true,header_flag=false;
	memset(key,'\0',sizeof(key));
	while ((c=getchar())!=EOF){
		if (key_flag){
			if (c=='\r') continue;
			if (c=='\n'){key_flag=false; header_flag=true; continue;}
			key[len][index++]=c;
			if (index==((1<<len)-1)){index=0;len++;}
		}
		else{
			
			//printf("asdfasf::::::::%s\n",key[1]);
			if (header_flag){
				
				//repeat 3 times for read header
				if (c=='\r'||c=='\n') c = getchar();
				header_len = header_len*2 + (c-'0');
				c = getchar();
				if (c=='\r'||c=='\n') c = getchar();
				header_len = header_len*2 + (c-'0');
				c = getchar();
				if (c=='\r'||c=='\n') c = getchar();
				header_len = header_len*2 + (c-'0');
				header_flag = false;
				
				//printf("\n header_len:%d\n",header_len);
				continue;
			}
			else{
				if (header_len == 0){printf("\n"); header_flag=true; key_flag=true; index=0; len=1; continue; }
				if (c=='\r'||c=='\n') continue;
				code_len=0;
				code_len = code_len*2 + c-'0';
				for (int i=1;i<=header_len-1;i++){
					c=getchar();
					if (c=='\r'||c=='\n') c = getchar();
					code_len = code_len*2 + c - '0';
				}
				//printf("%d ",code_len);
				//printf("header_len:%d code_len:%d\n",header_len,code_len);
				
				if (code_len == (1<<header_len)-1){
					//printf("\n!");
					header_flag=true;	
					header_len=0;
					continue;
				}
				else{
					printf("%c",key[header_len][code_len]);
				}
			}
		}
	} 
	return 0;
}

