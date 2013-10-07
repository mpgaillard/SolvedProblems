//http://coj.uci.cu/24h/problem.xhtml?abb=2538
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

ll poss[3050];


const ll mod = 1e9;


ll subsetSum(int n, vector<ll> nums){
	poss[0] = 1;

	for(int i=0; i<nums.size(); i++){
		for(int j=3000; j>=nums[i]; j--){
			poss[j] = (poss[j]+poss[j-nums[i]])%mod;
		}
	}
	ll res=0;
	for(int i=3; i<=3000; i+=3){
		res = (res+poss[i])%mod;
	}
	
	return res;
}

int main(){
	int N;
	int tmp;

	cin >> N;
	vector<ll> nums;
	ll divs_three = 0;
	for(int i=0; i < N; i++){
		cin >> tmp;
		tmp %= 3;
		if (tmp == 0) nums.push_back(3);
		else nums.push_back(tmp);
	}
	
	cout << subsetSum(N, nums) << endl;	


	return 0;
}