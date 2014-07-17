#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

typedef long long ll;

ll memo[51][51][51];

ll BC(int n, int k, int m){
	if(n<= 0) return 0;
	if(k==1){
		if(n <= m){
			return (memo[n][k][m]=1);
		}
		else{
			return (memo[n][k][m]=0);
		}
	}

	if(memo[n][k][m] != -1) return memo[n][k][m];
	else{

		ll sum=0;
		for (int i = 1; i <= m; i++)
		{
			sum += BC(n-i, k-1, m);
		}
		return (memo[n][k][m]=sum);
	}
}


int main(){

	int n, m, k;
	memset(memo, -1, sizeof(memo));

	while(cin >> n >> m >> k){
		cout << BC(n, m, k)<<endl;

	}

	

	return 0;
}