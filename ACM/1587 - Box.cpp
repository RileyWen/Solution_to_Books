#include <cstdio>
#include <cstring>
int leng[6][2],sum=0,d=0;
bool used_len[10000],used_pallet[6],identical=0;
bool match(int i,int j){
	if ( (leng[i][1]==leng[j][1]&&leng[i][0]==leng[j][0]) || (leng[i][0]==leng[j][1]&&leng[i][1]==leng[j][0]) )
		return true;
	return false;
}
int main(){
	while (scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&leng[0][0],&leng[0][1],
											&leng[1][0],&leng[1][1],
											&leng[2][0],&leng[2][1],
											&leng[3][0],&leng[3][1],
											&leng[4][0],&leng[4][1],
											&leng[5][0],&leng[5][1])==12){
	memset(used_len,0,sizeof(used_len));
	memset(used_pallet,0,sizeof(used_pallet));
	d=sum=0;
		for (int i=0;i<5;i++)
			for (int j=i+1;j<6;j++)
				if (!used_pallet[i]&&!used_pallet[j])
					if (match(i,j)){
						//printf("i=%d,j=%d\n",i,j);
						sum++;
						used_pallet[i]=true;
						used_pallet[j]=true;
					}
		if (sum<3){
			printf("%s","IMPOSSIBLE\n");
		//	printf("\nsum=%d\n",sum);
			continue;
		}
		else{
			for (int i=0;i<6;i++)
				for (int j=0;j<2;j++)
					if (!used_len[ leng[i][j] ]){
						used_len[ leng[i][j] ]=true;
						d++;
					}
					
			if (d>3){
				printf("%s","IMPOSSIBLE\n");
				continue;
			}
			else{
				
				printf("%s","POSSIBLE\n");
			}
		}
		
	}
	return 0;
}
