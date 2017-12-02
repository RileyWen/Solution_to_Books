#include <stdio.h>
#include <time.h>
void generate_random_walk(char map[12][12],char x[4],char y[4]){
	char cnt=1,i=1,j=1,tmp;
	srand(time(0));
	while (cnt<26){
		if (map[ i+x[0] ][ j+y[0] ] && map[ i+x[1] ][ j+y[1] ] && \
			map[ i+x[2] ][ j+y[2] ] && map[ i+x[3] ][ j+y[3] ])
			break;
		while (tmp = rand()%4, map[ i+x[tmp] ][ j+y[tmp] ]) {}
		map[ i+=x[tmp] ][ j+=y[tmp] ] = 'A' + cnt++;
	}
}
void print_array(char map[12][12]){
	int i,j;
	for (i=1;i<=10;printf("\n"),i++)
		for (j=1;j<=10;j++)
			printf("%c ",map[i][j]?map[i][j]:'.');
}
int main(){
	char x[4]={ 0, 0,-1, 1},y[4]={ 1,-1, 0, 0};
	char map[12][12]={
	'A','A','A','A','A','A','A','A','A','A','A','A',
	'A','A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A',
	'A','A','A','A','A','A','A','A','A','A','A','A'};
	
	generate_random_walk(map,x,y);
	print_array(map);
	
	return 0;
}
