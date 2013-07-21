

#include <iostream>
#include <stdio.h>

using namespace std;



int main(int argc, const char * argv[])
{
    

    int t, D, I;
    
    while (scanf("%d", &t) != EOF) {
      
        
        if(t == -1) break;
        
        while (t-- >0) {
            scanf("%d %d", &D, &I);
            int final=1;
            
            for (int i=1; i<D; i++) {
                if (I%2==0) {
                    final = (final*2)+1;
                }
                else final = final*2;
                
                I =(I+1)/2;
            }
            
            printf("%d\n", final);
            
        }
        
    }
    
    
    return 0;
}

