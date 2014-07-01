#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}


int main(){

	int Y, W;

	cin >> Y >> W;

	int points = (6-max(Y, W))+1;

	int g_div = gcd(6, points);

	cout << points/g_div << "/" << 6/g_div << endl;

	return 0;
}