#include <cstdio>
#include <cstring>
int m,n,hamming_dis=0,min_index=1;
char s[51][1002],smin[1002];
inline char num_to_char(int i)
{
	switch (i){
		case 0:	return 'A';
		case 1:	return 'C';
		case 2:	return 'G';
		case 3:	return 'T';
	}
}
bool cmp(char* s1,char* s2)//Èç¹û×ÖµäĞòs1>s2,return true
{
	//n=strlen(s1);
	for (int i=0;i<n;i++)
		if (s1[i]!=s2[i]){ 
			if (s1[i]>s2[i])
				return true;
			else
				return false;
		}
	return false;
}
int letter_of_least_hamming_distance(char* s1,char* s2){
	int sum=0;
	for (int i=0;i<n;i++){
		if (s1[i]!=s2[i])
			sum++;
	}
	return sum;
}
int main(){
	int frequency[4],T,tmp,tmp_index;
	scanf("%d",&T);
	
	while (T--){
		scanf("%d%d",&m,&n);
		hamming_dis=0;
		memset(smin,'\0',sizeof(smin));
		
		for (int i=1;i<=m;i++){
			scanf("%s",s[i]); 
		}
		
		//record all hamming_distance
		for (int i=0;i<n;i++){
			
			tmp=0;
			frequency[0]=frequency[1]=frequency[2]=frequency[3]=0;
			
			//max frequency of a,c,g,t in current line
			for (int j=1;j<=m;j++){
				//printf("%c",s[j][i]);
				switch (s[j][i]){
					case 'A':	frequency[0]++;
								break;
					case 'C':	frequency[1]++;
								break;
					case 'G':	frequency[2]++;
								break;
					case 'T':	frequency[3]++;
								break;
				}
			}
			//printf("\n");
			for (int j=0;j<4;j++){
				if (tmp<frequency[j]){
					tmp=frequency[j];
					tmp_index=j;
				}
			}
			//printf("line%d:%d char:%c\n",i,frequency[tmp_index],num_to_char(tmp_index));
			
			//compute hamming distance in current line
			for (int j=0;j<4;j++){
				if (tmp_index!=j){
					hamming_dis+=frequency[j];
				}
			}
			
			//record the most frequent letter
			smin[i]=num_to_char(tmp_index);
		}
		printf("%s\n%d\n",smin,hamming_dis);
		//printf("s1:%s\ns2:%s\nhamming_distance:%d\n",s[1],s[2],hamming_distance(s[1],s[2]));
		//printf("if s1 bigger than s2:%s",cmp(s1,s2)?"yes":"no");
	}
	return 0;
}
