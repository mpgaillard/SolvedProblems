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

struct point {
	int x, y;
};

bool c2pr(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
				(p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<point> ps;
	for (int i = 0; i < N; ++i) {
		point p;
		cin >> p.x >> p.y;
	}
	return 0;
}