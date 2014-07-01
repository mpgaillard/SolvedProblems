#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int trees[3005];

int main(){

	int n, v;
	int a, b;
	
	cin >> n >> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		trees[a] += b;
	}


	int picked = 0;
	int temp_picked;

	for(int i=0; i<3002; i++){
		int can_pick = v;
		for(int j=i-1; j<= i ; j++){
			if(j >= 0){
				temp_picked = min(trees[j], can_pick);
				picked += temp_picked;
				trees[j] -= temp_picked;
				can_pick -= temp_picked;
			}
		}
	}

	cout << picked << endl;

}