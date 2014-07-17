#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

double dep[120];

int main(){

	int month, months, dep_records;
	double down, amnt_loan, dep_rate, car_val, monthly_payment;

	
	while(cin >> months >> down >> amnt_loan >> dep_records){
		if(months < 0) break;
		for(int i=0; i<= months; i++) dep[i] = 0.0;
 		while(dep_records--){ 
			cin >> month >> dep_rate;
			dep[month] =  dep_rate;
		}
		dep_rate = 0.0;
		car_val = amnt_loan+down;
		monthly_payment = amnt_loan/(double)months;
		
		
		int i;
		for(i=0; i<= months; i++){
			if(dep[i] > 0.0) dep_rate = dep[i];


			car_val = (car_val)*(1.0-dep_rate);
			if(amnt_loan < car_val) {
				if(i == 1) cout << i << " month\n";
				else cout << i << " months\n";
				break;
			}
			amnt_loan -= monthly_payment;
		}


	}
	
	return 0;
}