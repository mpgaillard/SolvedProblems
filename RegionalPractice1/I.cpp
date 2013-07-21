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

#define pb push_back
#define mp make_pair

#define X first
#define Y second

typedef long long ll;

const int INF = (int) 1e9;
const double PI = 4 * atan(1);

int main() {
	vector<pair<int, int> > p;
	for (int i = 0; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		p.pb(mp(x, y));
	}
	sort(p.begin(), p.end());
	if (p[0].Y == p[1].Y && p[1].X == p[2].X) {
		cout << p[0].X << " " << p[2].Y << endl;
	} else if (p[0].Y == p[2].Y && p[0].X == p[1].X) {
		cout << p[2].X << " " << p[1].Y << endl;
	} else if (p[0].Y == p[2].Y && p[1].X == p[2].X) {
		cout << p[0].X << " " << p[1].Y << endl;
	} else {
		cout << p[2].X << " " << p[0].Y << endl;
	}
	return 0;
}