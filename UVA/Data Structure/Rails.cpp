#include <iostream>
#include <cstring>
#include <stack> 
#include <vector>

using namespace std;




int main(){

	int N, tmp;
	int order[1005];
	int after_arrange[1005];

	int t = 0;
	while(cin >> N){
		if (N == 0) break;
		
		//if(t++ > 0) cout << "\n";
		while(cin >> order[1]){
			stack<int> station;
			if (order[1] == 0) break;
			
			for(int i=2; i <= N; i++){
				cin >> order[i];
			}

			int i, j;
			for(i=1, j=1;  i <= N; ){

				if(station.empty() || station.top() < order[i] ){
					station.push(j);
					j++;
				}
				else if(station.top() == order[i]){
					station.pop();
					i++;
				}
				else break;
			}
			
			
			if(i == N+1) cout << "Yes" << endl;
			else cout << "No" << endl;
			
		}
		cout << "\n";
		
	}
	
	
	return 0;
}