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

#define ALL(X) X.begin(),X.end()

#define X first
#define Y second

typedef long long ll;

const int INF = (int) 1e9;
const double PI = 4 * atan(1);

int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > points;
	map<int, vector<int> > xs;
	map<int, vector<int> > ys;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		xs[x].pb(y);
		ys[y].pb(x);
		points.pb(mp(x, y));
	}
	for (map<int, vector<int> >::iterator it = xs.begin(); it != xs.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	for (map<int, vector<int> >::iterator it = ys.begin(); it != ys.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		pair<int, int> p = points[i];
		ans += (xs[p.X].end() - upper_bound(ALL(xs[p.X]), p.Y)) * (ys[p.Y].end() - upper_bound(ALL(ys[p.Y]), p.X));
		ans += (lower_bound(ALL(xs[p.X]), p.Y) - xs[p.X].begin()) * (ys[p.Y].end() - upper_bound(ALL(ys[p.Y]), p.X));
		ans += (lower_bound(ALL(xs[p.X]), p.Y) - xs[p.X].begin()) * (lower_bound(ALL(ys[p.Y]), p.X) - ys[p.Y].begin());
		ans += (xs[p.X].end() - upper_bound(ALL(xs[p.X]), p.Y)) * (lower_bound(ALL(ys[p.Y]), p.X) - ys[p.Y].begin());
	}
	cout << ans << endl;
	return 0;
}