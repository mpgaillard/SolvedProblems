//Valera and Antique Items
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int n, v, k;
	int tmp;

	cin >> n >> v;
	vector<int> people;
	for(int i = 0; i<n ; i++){
		cin >> k;
		bool a = true;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp;
			if(v > tmp && a){
				a = false;
				people.push_back(i+1);
			}
		}
	}
	if(people.size() == 0){
		cout << 0 << endl;
	}
	else{
		cout << people.size() << endl;
		cout << people[0];
		for (int i = 1; i < people.size(); ++i)
		{
			cout << " " << people[i] ;
		}
		cout << endl;
	}

	return 0;
}