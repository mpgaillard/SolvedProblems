//http://coj.uci.cu/24h/problem.xhtml?abb=2537

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;



int main(){
	
	int t, N;
	int p_move[10];
	cin >> t;
	while(t--){
		cin >> N;
		vector<int> perm_player(N);
		ll ct = 0;

		for (int i = 0; i < N; i++) {
			cin >> p_move[i];
			perm_player[i] = i;
		}
		
		do{
			vector<int> cards(N, 0);
			for(int i = 0; i < N; i++){
				for(int j=0; j< N; j++){
					if(cards[ (p_move[perm_player[i]]+j)%N ] == 0){
						cards[ (p_move[perm_player[i]]+j)%N ] = 1;
						if(perm_player[i]==0 && j == 0) ct++;
						break;
					}
				}
				
			}

		}while(next_permutation(perm_player.begin(), perm_player.end()));
		cout << ct << endl;

	}

	return 0;
}