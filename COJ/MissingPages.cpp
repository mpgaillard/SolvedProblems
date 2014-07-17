#include <stdio.h>

int main(){
	int N, P, block;
	int res[4];
	
	while(scanf("%d", &N)){
		if(N==0) break;
		scanf("%d", &P);

		if(P > N/2){
			block = (N-P)/2;
		}
		else{
			block = (P-1)/2;
		}

		res[0] = block*2 + 1;
		res[1] = block*2 + 2;
		res[2] = N-(block*2)-1;
		res[3] = N-(block*2);

		bool first = true;
		for(int i=0; i<4; i++){
			if(res[i] != P){
				if(!first) printf(" ");
				printf("%d", res[i]);
				first = false;
			}
		}
		printf("\n");
	}

	return 0;
}