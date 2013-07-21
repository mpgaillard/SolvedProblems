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

int points[2555];

int main() {
	int b, c, tc = 1;
	while (cin >> b >> c && b != 0) {
		memset(points, 0, sizeof(points));
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < c; ++j) {
			int w;
			cin >> w;
			points[w] += c - j;
		}
	}
	vector<pair<int, int> > V;
	for (int i = 0; i < c; ++i) {
		V.pb(mp(-points[i], i));
	}
	sort(V.begin(), V.end());
	if (c > 1 && V[0].first == V[1].first) cout << "Case " << tc++ << ": " << "No Condorcet winner" << endl;
	else cout << "Case " << tc++ << ": " << V[0].second << endl;
	}
	return 0;
}