#include <iostream>

using namespace std;

typedef long long ll;

ll dp[20];

int main(){

	
	int N, K;
	cin >> N >> K;
	dp[1] = K-1;
	dp[2] = K*(K-1);

	for (int i = 3; i <= N; i++)
	 {
	 	dp[i] = (K-1)*(dp[i-1]+dp[i-2]);
	 } 
	 cout << dp[N] << endl;

	return 0;
}