#include <iostream>
#include <algorithm>

using namespace std;

#define N 6
int dogs[N];

int choose(int pos, int sum, int T){

	if(pos == N){
		return (T - sum == 0) ? 1 : 0;
	}
	else{
		return max( choose(pos+1, sum, T), choose(pos+1, sum+dogs[pos], T-dogs[pos]) );
	}

}


int main(){
	ios_base::sync_with_stdio(false);
	int A;

	cin >> A;
	for (int i = 0; i < A; ++i)
	{
		int T = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> dogs[j];
			T+= dogs[j];
		}
		if( choose(0, 0, T)==1 ){
			cout << "Tobby puede cruzar\n";
		}
		else{ 
			cout << "Tobby no puede cruzar\n";
		}
	}


	return 0;
}