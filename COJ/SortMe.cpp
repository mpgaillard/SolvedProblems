#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct word{
	string orig;
	string perm;
};

bool cmp(word a, word b){
	return a.perm < b.perm;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	word words[40];
	int n, permVal[40];
	string alphabet;

	int year = 1;
	while(cin >> n){
		if(n == 0) break;
		cin >> alphabet;
		for (int i = 0; i < alphabet.length(); i++)
		{
			permVal[ alphabet[i]-'A' ] = i;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> words[i].orig;
			words[i].perm = words[i].orig;
			for(int j=0; j<words[i].orig.length(); j++) words[i].perm[j] = 'A' + permVal[ words[i].perm[j]-'A' ];	
		}

		sort(words, words+n, cmp);
		cout << "year " << year++ << "\n";
		for (int i = 0; i < n; ++i)
		{
			cout << words[i].orig << "\n";
		}			

	}


	return 0;
}