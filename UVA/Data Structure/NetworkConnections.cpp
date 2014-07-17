//
//  main.cpp
//  Friends
//
//  Created by Michael Pena Gaillard on 9/12/12.
//  Copyright (c) 2012 PUCMM. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cstring>

using namespace std;

//UNIONFIND
int id[1000000];
int sz[1000000];


int root(int i){
    while (i != id[i]) {
        i = id[i];
    }
    return i;
}

bool connected(int p, int q){
    return  root(p)==root(q);
}

void Union(int p, int q ){
    int i = root(p);
    int j = root(q);
    if(i==j) return;
    
    if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    }
    else {
        id[j] = i;
        sz[i] += sz[j];
    }
}


int main(int argc, const char * argv[])
{
    
    int t;
    int n_comps;
    int c1, c2;
    
    char instruction;
    scanf("%d", &t);
    int correct, incorrect;
    
    while (t-->0) {
        scanf("%d", &n_comps);
        
        correct = incorrect = 0;
        
        //printf("%d\n", n_comps);
        for (int i=1; i<=n_comps; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        getchar();
        while ((instruction = getchar()) && isalpha(instruction)) {
            
            scanf("%d %d", &c1, &c2);
            
            if (instruction == 'c') {
                Union(c1, c2);
            }
            else {
                connected(c1, c2)? correct++:incorrect++;
            }
            getchar();
        }
        
        printf("%d,%d\n", correct, incorrect);
        if (t>0) {
            printf("\n");
        }
    }
    
    
    
    return 0;
}