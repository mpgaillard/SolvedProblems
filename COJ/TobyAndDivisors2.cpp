#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 1000001

int divis[MAX];
int DP[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	
	int A, N, divisors, num;

	for(int i=1; i< MAX; i++) divis[i] = 1;


	for(int j=2; j< MAX; j++){
		for(int k=j; k< MAX; k+=j){
			divis[k]++;
		}
	}

	DP[1] = 1;
	int amnt_divs = 1;
	for(int i=2; i<MAX; i++){
		if(divis[i] > amnt_divs){
			DP[i] = i;
			amnt_divs = divis[i];
		}
		else{
			DP[i] = DP[i-1];
		}
	}


	cin >> A;

	
	for (int i = 0; i < A; i++)
	{
		cin >> N;
		cout << DP[N] << "\n";
	}


	return 0;
}