//http://coj.uci.cu/24h/problem.xhtml?abb=2537

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int inf = (1<<30);

int main(){
	
	int t, K;
	string S;

	cin >> t;
	while(t--){
		int l_so_far = 0;
		int max_so_far = 0;
		int pos_max = 0;
		int pos = 0;
		cin >> K >> S;

		vector<int> lesser(S.length(), 0);
		vector<int> greater(S.length(), 0);

		if(S[0] == '<') lesser[0]++;
		if(S[0] == '>') greater[0]++;

		for (int i = 1; i < S.length(); i++)
		{
			lesser[i] = lesser[i-1];
			greater[i] = greater[i-1];
			if(S[i] == '<') {
				lesser[i]++;
			}
			else {
				greater[i]++;
			}
		}

		if(greater[S.length()-1] <= K || lesser[S.length()-1] <= K){
			cout << S.length() << endl;
		}
		else if(K==0){
			int l = 1;
			int ml = 1;
			for (int i = 1; i < S.length(); i++)
			{
				if(S[i] == S[i-1])l++;
				else l = 1;
				if(l > ml) ml = l;
			}
			cout << ml << endl;
		}
		else{
			int start = 0;
			int end = start;
			int smaller_signs = 0;
			while(end < S.length() && start <= end){

				if(smaller_signs <= K){
					if(S[end] == '<'){
						smaller_signs++;
					}
					end++;
				}
				else{
					if(S[start] == '<'){
						smaller_signs--;
					}
					start++;
				}
				if(smaller_signs <= K){
					if ( end-start  > max_so_far) max_so_far = end-start ;
				}
			}
			start = 0;
			end = start;
			int greater_signs = 0;
			while(end < S.length() && start <= end){

				if(greater_signs <= K){
					if(S[end] == '>'){
						greater_signs++;
					}
					end++;
				}
				else{
					if(S[start] == '>'){
						greater_signs--;
					}
					start++;
				}
				if(greater_signs <= K){
					if ( end-start  > max_so_far) max_so_far = end-start ;
				}
			}

			cout << max_so_far << endl;
		}

	}


	return 0;
}