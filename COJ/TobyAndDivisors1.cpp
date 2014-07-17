#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int divis[2501];

int main(){
	ios_base::sync_with_stdio(false);
	
	int A, N, divisors, num;

	for(int i=1; i<= 2500; i++) divis[i] = 1;


	for(int j=2; j<= 2500; j++){
		for(int k=j; k<= 2500; k+=j){
			divis[k]++;
		}
	}

	cin >> A;

	
	for (int i = 0; i < A; i++)
	{
		cin >> N;
		divisors = 1;
		num = 1;
		for(int j=1; j <= N; j++){
			if(divis[j] > divisors){
				divisors = divis[j];
				num = j;
			}
		}
		cout << num << "\n";
	}




	return 0;
}