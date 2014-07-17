#include <iostream>
#include <cstring>

using namespace std;


int main(){

	double H, U, D, F;

	while(cin >> H >> U >> D >> F){
		if( H == 0) break;
		double fatigue_effect = U*(F/(double)100.0);

		double  distance_climbed=0.0, height_after_climb, height_after_slide;
		int day = 1;

		while(true){
			distance_climbed += max(U, 0.0);
			//cout << distance_climbed << endl;
			if(distance_climbed > H) {
				cout << "success on day " << day << endl;
				break;
			}

			distance_climbed -= D;
			U -= fatigue_effect;
			if( distance_climbed < (double)0.0){
				cout << "failure on day " << day << endl;
				break;
			}
			day++;


		}

	}
	
	return 0;
}