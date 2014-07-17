#include <iostream>
#include <cstring>

using namespace std;

#define MAX 13

typedef long long ll;

ll Po[MAX+1][2];



ll BC[MAX+1][MAX+1];

void binomialCoefficient(int nMax, int kMax) {
    for (int i=0; i<=nMax; i++) BC[i][0] = 1;
    for (int j=0; j<=kMax; j++) BC[j][j] = 1;
    for (int i=1; i<=nMax; i++)
        for (int j=1; j<i; j++)
            BC[i][j] = BC[i-1][j-1] + BC[i-1][j];
}

ll fact(int n){
	ll res =1;
	for(int i=2; i<= n; i++){
		res*=i;
	}
	return res;
}



ll create_path(int n, int pos, int map){

	ll res = 0;
	if(pos == n+1){
		return 1;
	}

	for(int i=1; i<= n; i++){
		if(i == pos) continue;

		if( !(map & (1 << i )) ){
			map = map | (1 << i );
			res += create_path(n, pos+1, map);
			map = map ^ (1 << i);
		}
	}

	return res;
}


ll gcd(ll a, ll b){
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}

void calcPo(int n){


	ll VAL_NOM = Po[n][0] = 0;
	ll VAL_DENOM = Po[n][1] = 1;
	ll divis;

	for (int k = 1; k <= n ; k++)
	{
		//nom is BC, Po[n-k][0]
		//denom is PS, Po[n-k][1]
		ll Ps = 1;
		for(int j=n; j>n-k; j--){
			Ps *= j;
		}
		ll nom = BC[n][k]*Po[n-k][0];
		ll denom = Ps*Po[n-k][1];

		VAL_DENOM = Po[n][1]*denom;
		VAL_NOM = Po[n][0]*denom + nom*Po[n][1];

		divis = gcd(VAL_DENOM, VAL_NOM);

		Po[n][0] = VAL_NOM/divis;
		Po[n][1] = VAL_DENOM/divis;
	}

	Po[n][0] = Po[n][1]-Po[n][0];
}	



int main(){
	int t, n;
	ll divis, x;

	binomialCoefficient(13, 13);

	Po[0][0] = Po[0][1] = 1;
	Po[1][0] = 0, Po[1][1] = 1;
	Po[2][0] = 1, Po[2][1] = 2;

	for(int i=3; i<=12; i++){
		calcPo(i);
	}

	cin >> t;
	while(t--){
		cin >> n;
		divis = gcd(Po[n][1], Po[n][0]);
		Po[n][0] = Po[n][0]/divis;
		Po[n][1] = Po[n][1]/divis;

		x = fact(n)/Po[n][1];
		//cout << create_path(n, 1, 0) << "/" << fact(n) << endl;
		cout << Po[n][0]*x << "/" << Po[n][1]*x << endl;
	}

}