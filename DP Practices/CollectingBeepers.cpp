#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define INF 1000000000

int distances[11][11], memo[11][1<<11];
int x[11], y[11];
int x_s, y_s;
int start_x, start_y;
int n;

int best_path(int pos, int bitmask){
	if(bitmask == (1 <<n+1)-1) return distances[pos][0] ;
	if (memo[pos][bitmask] != -1) return memo[pos][bitmask];

	int answer = INF;
	for(int i=0; i<= n; i++){
		if(i != pos && !(bitmask & (1 << i)) ){
			answer = min(answer, distances[pos][i] + best_path(i, bitmask | (1 << i)));
		}
	}
	return memo[pos][bitmask] = answer;
}

int main(){
	int t;
	
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &x_s, &y_s);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for (int i = 1; i <= n ; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		for (int i = 0; i <= n ; i++)
		{
			for(int j=0 ; j <=n; j++){
				distances[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
			}
		}
		memset(memo, -1, sizeof(memo));
		printf("The shortest path has length %d\n", best_path(0, 1));
	}
}