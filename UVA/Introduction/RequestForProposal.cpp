#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;



int main(){


	int n, p, best_comp, comp;

	string tmp;
	double best_p, price;

	string best_proposal;

	int RFP = 1;
	while(cin >> n >> p){
		if(n == 0 && p == 0) break;
		best_comp = 0;
		getline(cin, tmp);
		for(int i=0; i<n; i++){
			getline(cin, tmp);
		}


		for(int j=0; j<p; j++){
			getline(cin, tmp);
			cin >> price >> comp;
			if(comp > best_comp || ( comp == best_comp && price < best_p ) ){
				best_comp = comp;
				best_p = price;
				best_proposal = tmp;
			}
			
			for(int k=0; k<=comp; k++){
				//cout << "here" << endl;
				getline(cin, tmp);
			}

		}
		if(RFP > 1) cout << endl;
		cout << "RFP #" << RFP++<<endl;
		cout << best_proposal << endl;
	}
	
	
	return 0;
}