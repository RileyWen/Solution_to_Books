#include <cstdio>
#include <cstring>
int solution[100005]; 
int main(){
	int T,sum=0,x;
	memset(solution,0,sizeof(solution));
	for (int i=1;i<=100000;i++){ 
		x=i;
		sum=x;
		while (x>0){ sum+=x%10; x/=10;}
		if (solution[sum]==0||i<solution[sum])solution[sum]=i; 
	} 
	scanf("%d",&T);
	while (T--){
		scanf("%d",&x);
		printf("%d\n",solution[x]);	
	}
	return 0;
}
