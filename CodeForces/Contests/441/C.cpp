#include <iostream>
#include <vector>
#include <utility>

using namespace std; 

vector< vector< pair< int, int > > > tubes;

int n, m;

void fillTable(int x, int y, int r, int k, int dir){
	if(r%2 == 0 && k > 0){
		vector< pair<int, int> > n_tube;
		n_tube.push_back( make_pair(y, x) );
		tubes.push_back(n_tube);
		k--;
	}
	else{
		tubes[ tubes.size()-1 ].push_back( make_pair(y, x) );
	}

	if(x+dir >= m || x+dir < 0) { dir *= -1; y++; x -= dir;}

	if(y < n) fillTable(x+dir, y, r+1, k, dir);

}

int main(){
	int k;
	cin >> n >> m >> k;
	fillTable(0, 0, 0, k, 1);

	for (int i = 0; i < tubes.size(); i++)
	{
		cout << tubes[i].size();
		for(int j=0; j<tubes[i].size(); j++) cout << " " << tubes[i][j].first+1 <<  " " << tubes[i][j].second+1;
		cout << endl;
	}

	return 0;
}