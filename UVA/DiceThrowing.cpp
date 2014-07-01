#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b){
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}

ll res[152][26];
int main(){
	int n, x;

	while(cin >> n >> x){
		if(n==0 && x==0) break;
		if(6*n < x) { cout << 0 << endl; continue;}
		if(n >= x) { cout << 1 << endl; continue;}

		memset(res, 0, sizeof(res));

		for(int i=1; i<=6; i++){
			res[i][1] = 1;
		}

		for(int i=2; i<=n; i++){

			for(int j=2; j<= 150; j++){

				for(int k=1; k<=6; k++){
					if(j-k < 1) break;
					res[j][i]+= res[j-k][i-1];
				}
			}
		}

		ll success = 0;
		for(int i=x; i<= 150; i++){
			success += res[i][n];
		}
		ll combs = pow(6, n);

		ll l_div = gcd(combs, success);

		success /= l_div;
		combs /= l_div;

		cout << success << "/" << combs << endl;


	}
	return 0;
}