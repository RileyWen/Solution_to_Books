#include <cstdio>
#include <cstring>

struct Command{
	char c[5];
	int a,r1,r2,c1,c2,x[15];
}cmd[10000];


//if gone,return false
bool simulate(int *r0,int *c0){
	
}

int main(){
	int r1,c1,r2,c2,r,c,n,q,r0,c0,kase=0;
	while (scanf("%d%d%d",&r,&c,&n)==3 && r){
		for (int i=0;i<n;i++){
			scanf("%s",&cmd[i]);
			if (cmd[i].c[0=='E'])
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else{
				scanf("%d",cmd[i].a);
				for (int j=0;j<a;j++)
					scanf("%d",&cmd[i].x[j]);
			}
		}
		if (kase>0) printf("\n");
		printf("Spreadsheet #",++kase);
		scanf("%d",&q);
		while (q--){
			scanf("%d%d",&r0,&c0);
			printf("Cell data in (%d,%d) ",r0,c0);
			if ()
			moved to (%d,%d)",)
		}
	}
}
