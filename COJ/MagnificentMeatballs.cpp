#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);

	int n, guests[40];

	while(cin >> n){
		if (n == 0) break;
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> guests[i];
			total += guests[i];
		}
		int so_far = 0;
		bool found = false;
		int pos = 0;
		for(int i=0; i<n; i++){
			so_far += guests[i];
			if(so_far == total-so_far){
				found = true;
				pos = i+1;
				break;
			}
		}

		if(found){
			cout << "Sam stops at position " << pos <<  " and Ella stops at position " << pos+1 << ".\n";
		}
		else{
			cout << "No equal partitioning.\n";
		}
	} 

	return 0;
}