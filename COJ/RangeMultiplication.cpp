#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MOD 1000000009

typedef long long ll;
int n;

const int inf = (1<<30);

const int seg_size = 2*((int)pow(2, (log(1000001)/log(2)) +1) );
ll M[4194305];//seg_size
ll add[4194305];

//init in 1
void initialize(int node, int b, int e, int N) {
  if (b == e){
   M[node] = 1;
   add[node] = 1;
  }
  else {
   initialize(2 * node, b, (b + e) / 2, N);
   initialize(2 * node + 1, (b + e) / 2 + 1, e, N);
   M[node] = ( (M[2*node]%MOD)+ (M[2*node+1]%MOD) )%MOD;
   add[node] = 1;
  }
}

void addToChildren(int node){
    add[2*node] = ((add[2*node]%MOD)*(add[node]%MOD))%MOD;
    add[2*node+1] = ((add[2*node+1]%MOD)*(add[node]%MOD))%MOD;
    M[2*node] = ((M[2*node]%MOD)*(add[node]%MOD))%MOD;
    M[2*node+1] = ((M[2*node+1]%MOD)*(add[node]%MOD))%MOD;
    add[node] = 1;
}


ll query(int node, int b, int e, ll i, ll j) {
  if (i > e || j < b)
   return 0;
  if (b >= i && e <= j)
   return (M[node]%MOD);
 
  addToChildren(node);
  return (query(2 * node, b, (b + e) / 2, i, j)%MOD +query(2 * node + 1, ((b + e) / 2)+1, e, i, j)%MOD)%MOD;
}

ll query(ll i, ll j) {
  return query(1, 1, n, i, j);
}

void update(int node, int b, int e, int i, int j, int val) {
  if (i > e || j < b)
   return;
  if (b >= i && e <= j) {
   M[node] = ((M[node]%MOD)*(val%MOD))%MOD;
   add[node] = ((add[node]%MOD)*(val%MOD))%MOD;
  } 
  else {
    addToChildren(node);
    update(2 * node, b, (b + e) / 2, i, j, val);
    update(2 * node + 1, (b + e) / 2 + 1, e, i, j,val);
    M[node] = ( (M[node * 2]%MOD) + (M[node * 2 + 1]%MOD))%MOD;
  }
}

void update(int node, int i, int j, int val) {
  update(node, 1, n, i, j, val);
}

int main(){
  ll N, M;
  ll x, y, k;  

  while(scanf("%lld %lld", &N, &M) != EOF){ 
    n = N;
    initialize(1, 1, N, N);
    int type;
    for(int i=0; i<M; i++){
      scanf("%d", &type);
      if(type == 0){
        scanf("%lld%lld%lld", &x, &y, &k);
        update(1, x, y, k);
      }
      else{
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", query(x, y));
      }

    }
  }
  return 0;
}

