#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){

	int S;
	int N;
	double p;
	int player;
	cin >> S;
	while(S--){
		//cin >> N >> p >> player;
		scanf("%d %lf %d", &N, &p, &player);
		if(p == 0.00) {printf("0.0000\n"); continue;}
		double p_comp = 1.0-p;
		double a = pow(p_comp, player-1)*p;
		double r = pow(p_comp, N);
		//cout << setprecision(4) << a/(1.0-r) << endl;
		printf("%0.4lf\n", a/(1.0-r));
	}

	return 0;
}