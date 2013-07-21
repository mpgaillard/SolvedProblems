#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

long long facto(int n)
{
	if(n==1)
		return 1;
	return n* facto(n-1);
}

int main()
{
	int N;
	long long D[10];
	cin>> N;
	while(N!=0)
	{
		long long total=0;
		int i=0;
		while(N!=0)
		{
			int d=N%10;
			N/=10;
			D[i++]=d;
		}
		for(int j=0;j<i;j++)
		{
			total+=(D[j]* facto(j+1));
		}
		cout<< total<< endl;
		cin>> N;
	}
}