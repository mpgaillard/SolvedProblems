//http://coj.uci.cu/24h/problem.xhtml?abb=2538
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll BC[1001][1001];

const ll mod = 1e9;

ll NChooseK(int N, int K){
	if(BC[N][K] != 0) return BC[N][K];
	if(N==K || K == 0){
		return (BC[N][K]=1);
	}
	else{
		return(BC[N][K] = ((NChooseK(N-1, K)%mod)+(NChooseK(N-1, K-1)))%mod );
	}
}

int main(){
	int N;
	int tmp;
	cin >> N;
	ll zeros=0, ones=0, twos=0;
	for(int i=0; i<N; i++){
		cin >> tmp;
		if(tmp%3 == 0) zeros++;
		else if(tmp%3 == 1) ones++;
		else twos++;
	}
	ll accum = 0;

	ll zeros_combs = 0;
	for(int i=1; i<=zeros; i++){
		zeros_combs = (zeros_combs+NChooseK(zeros, i))%mod;
	}


	ll ones_two_combs = 0;
	for(int i=0; i<=ones; i++){
		for(int j=0; j<= twos; j++){
			ll val = i + j*2;
			if( val == 0 ) continue;
			else if ( val%3 == 0 ){
				ones_two_combs = (ones_two_combs+( (NChooseK(ones, i)%mod) * (NChooseK(twos, j)%mod) )%mod)%mod;
			} 
		}
	}

	accum = ((zeros_combs + ones_two_combs)%mod + (zeros_combs*ones_two_combs)%mod)%mod;
	cout << accum << endl;


	return 0;
}