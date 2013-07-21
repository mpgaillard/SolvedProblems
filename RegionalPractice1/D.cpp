#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;
#define mod 100000000


typedef long long ll;

class activity{
public:
	ll start;
	ll end;
	ll ct;
	activity(){
		ct = 0;
	}
};

bool cmp(activity a, activity b){
	return a.start < b.start;
}

int main() {

	ll N, M;
	ll t1, t2;
	while(cin >> M >> N){
		bool no_start = true;
		bool no_end = true;
		if(N==0 && M==0) break;

		vector<activity> activities(N);
		for(int i=0; i<N; i++){
			cin >> t1 >> t2;
			activities[i].start = t1;
			activities[i].end = t2;
			if(t1==0) no_start = false;
			if(t2==M) no_end = false;
		}

		sort(activities.begin(), activities.end(), cmp);
		if(no_start || no_end){
			cout << 0 << endl;
		}
		else{
			for (int i = 0; i < N; i++)
			{
				for(int j=i+1; j<N;j++){
					if(activities[j].start <= activities[i].end && activities[j].end > activities[i].end){
						activities[j].ct = (((activities[j].ct%mod)+(activities[i].ct%mod))%mod+1)%mod;
					}
				}
			}

			ll sumres = 0;
			for(int i=0; i<N; i++){
				if(activities[i].end == M){
					sumres = ((sumres%mod)+(activities[i].ct%mod))%mod;
				}
			}
			cout << sumres << endl;
		}

	}


	return 0;
}