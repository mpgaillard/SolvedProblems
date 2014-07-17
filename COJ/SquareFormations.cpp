#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	int T, k;
	cin >> T;

	vector<int> sqrs;
	int fs = 1;
	while(fs*fs <= 1000000){
		sqrs.push_back(fs*fs);
		fs++;
	}

	for (int i = 1; i <= T; ++i)
	{
		cin >> k;
		for(int j=0; j<sqrs.size(); j++){
			if(sqrs[j] > k){
				if( (sqrs[j]-k)%2 == 0 && binary_search(sqrs.begin(), sqrs.end(), ((sqrs[j]-k)/2)+k  ) ){
					cout << "Case " << i << ": " << sqrs[j]-k << "\n";
					break;
				}
			}
		}

		
	}


	return 0;
}