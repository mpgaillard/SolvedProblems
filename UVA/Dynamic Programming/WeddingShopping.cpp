#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int garments_cost[23][23];
bool estados[21][201];
int answer;

void DFS(int sum, int curr_depth, int end_depth, int budget){
	if(curr_depth == end_depth){
		if(sum > answer) answer = sum;
		return;
	}
	for (int i = 1; i <= garments_cost[curr_depth][0]; i++)
	{
		if(sum+garments_cost[curr_depth][i] <= budget && !estados[curr_depth][sum+garments_cost[curr_depth][i]]){
			estados[curr_depth][sum+garments_cost[curr_depth][i]] = true;
			DFS(sum+garments_cost[curr_depth][i], curr_depth+1, end_depth, budget);
		}
	}
}
int main(){
	int t;
	int M, C, K;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &M, &C);
		memset(estados, 0, sizeof(estados));
		answer = -1;
		for (int i = 0; i < C; ++i)
		{
			scanf("%d", &garments_cost[i][0]);
			for (int j = 1; j <= garments_cost[i][0]; ++j)
			{
				scanf("%d", &garments_cost[i][j]);
			}
		}
		DFS(0, 0, C, M);
		if (answer == -1)
		{
		printf("no solution\n");
		}
		else {
			printf("%d\n", answer);
		}
	}
}