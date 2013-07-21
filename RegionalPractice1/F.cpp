#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
ll B[2000050];
ll YES[2000050];

int main() {
	int N;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(B, B+N);
	ll ct = 0;
	ll greatest = B[N-1];

	ll g_c = 0;
	for(int i=N-1; i>= 0; i--){
		if(B[i] != greatest) break;
		else{
			g_c++;
		}
	}

	if(B[0]+N >= greatest+g_c){
		YES[0] = 1;
		ct++;
	}
	
	for(int i=1; i<N-1; i++){
		if(B[i] == B[i-1]){
			if(YES[i-1]){
				YES[i]=1;
				ct++;
			}
		}
		else if(B[i]+N >= greatest+g_c && B[i]+N >= B[i+1]+(N-1)){
			ct++;
			YES[i]=1;
		}
	}
	ct++;

	cout << ct << endl;
	
	return 0;
}