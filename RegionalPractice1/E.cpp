#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;


ll primes[1000010];

int main()
{

	vector<ll> final_ps;
	ll max_val = 1000005;
	for (ll i = 2; i*i <=  max_val; i++)
	{
		if(primes[i]==1) continue;
		for(ll j = i*i; j<= max_val; j+=i )
		{
			primes[j] = 1;
		}
	}

	for (int i = 2; i < max_val; i++)
	{
		if (primes[i]==0){
			final_ps.push_back(i);
		}
	}
	vector<ll> almost;
	for(int i=0; i<final_ps.size(); i++){
		ll num=final_ps[i]*final_ps[i];
		while(num <= 1000000000000LL){
			almost.push_back(num);
			num*=final_ps[i];
		}
	}
	sort(almost.begin(), almost.end());



	int N;
	cin >> N;

	ll low, high;


	for (int i = 0; i < N; i++)
	{
		cin >> low >> high;
		cout << ((upper_bound(almost.begin(), almost.end(), high)-1) - lower_bound(almost.begin(), almost.end(), low) + 1) << endl;
	}
	
}