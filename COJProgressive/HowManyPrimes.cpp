#include <stdio.h>

#define AMT 1000000
int p_map[AMT+1];
int p_range[AMT+1];
int main(){

	for (int i = 2; i*i <= AMT; i++)
	{
		if (p_map[i]==1) continue;
		for (int j = i*i; j <= AMT; j+=i)
		{
			p_map[j] = 1;
		}
	}
	for(int i=2; i<= AMT; i++){
		p_range[i] = p_range[i-1]+(p_map[i]==0?1:0);
	}
	int l, r;
	while(scanf("%d %d", &l, &r)){
		if (l==0 && r==0) break;
		printf("%d\n", p_range[r]-p_range[l-1]);

	}

}