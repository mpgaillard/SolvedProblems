#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	
	int beds, curr_customers, walked;
	int customer[27];
	int invalid[27];

	string order;
	while(cin >> beds){
		if(beds == 0) break;
		cin >> order;
		curr_customers = 0;
		walked = 0;
		memset(customer, 0, sizeof(customer));
		memset(invalid, 0, sizeof(invalid));

		for (int i = 0; i < order.size(); i++)
		{
			if(invalid[ order[i] - 'A'] ) continue;

			if( customer[ order[i] - 'A' ] == 0){
				if(curr_customers == beds) {
					invalid[ order[i] - 'A' ] = 1;
					walked++;
				}
				else{
					customer[order[i] - 'A' ] = 1;
					curr_customers++;
				}
			}
			else{
				customer[ order[i] - 'A' ] = 0;
				curr_customers--;
			}			
		}
		if(walked == 0){
			cout << "All customers tanned successfully.\n"; 
		}
		else{
			cout << walked << " customer(s) walked away.\n";
		}
	}	


	return 0;
}