#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int divis[2501];

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, diff;
	int nums[1001];
	cin >> n;

	nums[0] = 1000000000-1;
	cout << nums[0];

	diff = 1002;


	for(int i=1; i<n; i++){
		nums[i] = nums[i-1]-diff;
		diff--;
		cout << " " << nums[i];
	}
	cout << "\n";

	return 0;
}