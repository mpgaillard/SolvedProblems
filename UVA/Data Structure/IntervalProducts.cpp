#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iostream>
using namespace std;

struct num{
	int negat, zero;
};

num bit[100001];
int nums[100001];
int N, K;

num operator-(num a, num b){
	num temp;
	temp.negat = a.negat-b.negat;
	temp.zero = a.zero-b.zero;
	return temp;
}

void anadir(int i, int y, int last){
	if(y == last) return;

    while (i<= N) {//Length
        if(y<0) bit[i].negat++;
        else if(y==0) bit[i].zero++;
        if(last == 0) bit[i].zero--;
        else if (last < 0 && last != -10) bit[i].negat--;
        i+= (i & (-i));
    }
}

num sumaParcial(int i){
    num sum;
    sum.negat = sum.zero = 0;
    while (i>0) {
        sum.negat += bit[i].negat;
        sum.zero += bit[i].zero;
        i-= (i & (-i));
    }
    return sum;
}

num sumaParcial(int a, int b){
	num temp;
	temp.negat = temp.zero = 0;
    return sumaParcial(b)-(a==1 ? temp : sumaParcial(a-1));
}

int main(){

	
	char comm[3];
	int Xi, Xj;
	int temp;
	while(scanf("%d %d", &N, &K) != EOF){
		for(int i=0; i<=N; i++){
			bit[i].negat = bit[i].zero = 0;
		} 
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &nums[i]);
			if(nums[i] > 0) nums[i] = 1;
			else if(nums[i] < 0) nums[i] = -1;
			else nums[i] = 0;
			if(nums[i] <=0) anadir(i, nums[i], -10);
		}

		for (int i = 0; i < K; i++)
		{
			scanf("%s %d %d", comm, &Xi, &Xj);
			if(comm[0] == 'C'){
				if(Xj > 0) Xj = 1;
				else if(Xj < 0) Xj = -1;
				else Xj =0;
				int last = nums[Xi];
				nums[Xi] = Xj;
				anadir(Xi, Xj, last);
			}
			else{
				num sum = sumaParcial(Xi, Xj);
				if(sum.zero > 0) printf("0");
				else if(sum.negat%2 == 1) printf("-");
				else printf("+");
			}
		}
		printf("\n");
	}

	return 0;
}