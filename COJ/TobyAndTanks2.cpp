#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

ll tanks[100005];

int b_search(int l, int r, int n, int cq){
	int m;
	while(l <= r){
		m = l + (r-l)/2;
		if(cq-tanks[m] >= 1 && ( m+1 == n || cq - tanks[m+1] < 1 ) ){
			return m+1;
		}
		else{
			if( cq-tanks[m] < 1 ){
				r = m-1;
			}
			else{
				l = m+1;
			}
		}
	}
	return l >= n ? n : 1; 
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, q;
	int queries[10005];

	while(cin >> n >> q){
		for(int i=0; i < n; i++){
			cin >> tanks[i];
			if(i > 1) tanks[i] += tanks[i-1];
		}
		for(int i=0; i<q ; i++){
			cin >> queries[i];
		}

		cout << b_search(1, n-1, n, queries[0]);
		for(int i=1; i<q; i++){
			cout << " " << b_search(1, n-1, n, queries[i]);
		}
		cout << "\n";

	}

	return 0;
}