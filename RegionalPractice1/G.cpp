#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;



int main() {
	int b,c;
	int cases=1;
	ll C[2505];
	cin >> b>> c;
	while(b!=0 && c!=0)
	{
		for(int i=0;i<c;i++)
		{
			C[i]=0;
		}
		for(int i=0;i<b;i++)
		{
			for(int j=0;j<c;j++)
			{
				ll temp;
				cin>> temp;
				C[temp]+=c-j;
			}
		}
		int max=0;
		bool rep=false;
		for(int i=0;i<c;i++)
		{
			if(C[i]>C[max] || i==0)
			{
				max=i;
				rep=false;
			}
			else if(C[i]==C[max])
			{
				rep=true;
			}
		}
		if(rep)
		{
			cout<< "Case "<< cases++<<": No Condorcet winner"<< endl; 
		}
		else{
			cout<< "Case "<< cases++<<": "<<max<<endl; 
		}
		cin >> b>> c;
	}	
	return 0;
}