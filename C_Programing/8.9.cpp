#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
char map[12][12]={{'A','A','A','A','A','A','A','A','A','A','A','A'},
				  {'A','A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
			 	  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A', 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'A'},
				  {'A','A','A','A','A','A','A','A','A','A','A','A'}};
char x[4]={ 0, 0,-1, 1},y[4]={ 1,-1, 0, 0};
int main(){
	srand(time(0));
	char cnt=1,i=1,j=1,tmp,dot = '.';
	while (cnt<26){
		if (map[ i+x[0] ][ j+y[0] ] && map[ i+x[1] ][ j+y[1] ] && map[ i+x[2] ][ j+y[2] ] && map[ i+x[3] ][ j+y[3] ])
			break;
		while (tmp = rand()%4, map[ i+x[tmp] ][ j+y[tmp] ]) {}
		map[ i+=x[tmp] ][ j+=y[tmp] ] = 'A' + cnt++;
	}
	for (int i=1;i<=10;i++,cout<<endl)
		for (int j=1;j<=10;j++)
			cout<<(map[i][j]?map[i][j]:dot)<<' ';
	//getchar();
	return 0;
} 
