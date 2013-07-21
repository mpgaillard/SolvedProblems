#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
#define MAXIND 264000

typedef vector<long long> vll;

long long powers[100010];

long long fastpow(int a, int n, int modlim){
    
    if (n==0) {
        return 1;
    }
    else if(n==1){
        return a;
    }
    else {
        long long f = fastpow(a, n/2, modlim)%modlim;
        if (n%2==0) {
            return (((f)*(f))%modlim);
        }
        else {
            return ((((a%modlim)*(f))%modlim)*(f))%modlim;
        }
    }
}

//FENWICK TREE
void anadir(int i, long long y, vll& bit, int n, int P){
    while (i<= n) {
        bit[i] = (bit[i]%P+ y%P)%P;
        //cout << bit[i]<<endl;
        i+= (i & (-i));
    }
}

long long sumaParcial(int i, vll& bit, int P){
    long long sum=0;
    while (i>0) {
        //sum += bit[i];
        sum = (sum%P + bit[i]%P)%P;
        i-= (i & (-i));
    }
    return sum;
}



long long sumaParcial(int a, int b, vll& bit, int P){
    return ((sumaParcial(b, bit, P)%P) - (a==1 ? 0 : sumaParcial(a-1, bit, P)%P))%P;
}

long long M[MAXIND];

void initialize(int node, int b, int e, int M[MAXIND], int A[MAXIND], int N){
    if (b==e) {
        M[node] = b;
    }
    
    
}

int main(int argc, const char * argv[])
{

    cin.ios_base::sync_with_stdio(0);
    int B, P, L, N;
    long long sum;
    long long div;
    while (cin>>B>>P>>L>>N) {
        if (B==0) {
            break;
        }
        vll bit(L+1, 0);
        vll V_NUMS(L+1, 0);
        
        
        
        for (int i=1; i<=L; i++) {
            powers[i] = fastpow(B, (L-i), P);
        }
        
        char command;
        int comm_a, comm_b;
        for (int i=0; i<N; i++) {
            cin >> command >> comm_a >> comm_b;
            if (command == 'H') {
                sum = sumaParcial(comm_a, comm_b, bit, P);
                cout << sum << endl;
                div = L-comm_b;
                div = powers[L-div];
                sum = ((div%3)*sum)%P;
                cout << sum << endl;
            }
            else {
                anadir(comm_a, V_NUMS[comm_a]*-1, bit, L, P);
                V_NUMS[comm_a] = (powers[comm_a]*(comm_b%P))%P;
                anadir(comm_a, V_NUMS[comm_a], bit, L, P);
            }
            
        }
        
        
        cout << "-"<<endl;
        
    }
    
    
    
    return 0;
}

