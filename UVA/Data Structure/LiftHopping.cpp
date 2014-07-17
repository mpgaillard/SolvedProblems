
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <string.h>

using namespace std;




#define INF 1000000000

struct data_node{
    int v;
    int distance;
};

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, data_node> id;
int n;

int dijkstra(int start, int end, vector< vector<data_node> >& AdjList ){
    vi dist(500, INF);
    dist[start] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    
    pq.push(ii(0, start));
    
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first;
        int u = front.second; 
       // printf("%d\n", u);
        if (d == dist[u]) {
            for (int j=0; j < (int)AdjList[u].size(); j++) {
                data_node v = AdjList[u][j];
                if (dist[u] + v.distance < dist[v.v]) {
                    dist[v.v] = dist[u]+v.distance;
                    pq.push(ii(dist[v.v], v.v));
                }
            }
        }
    }
    
    int min_res = INF;
    
    for (int i=0; i<n; i++) {
        if (dist[end+(i*100)] < min_res) {
            min_res = dist[end+(i*100)];
        }
    }
    
    return min_res;  
}

int main(int argc, const char * argv[])
{
    int k;//destination
    int Ti[6];
    int first_node, second_node;
    char line[1000];
    bool map[5][100];
    
    char* pch;
    data_node temp;
    while(scanf("%d %d", &n, &k)!=EOF){
        memset(map, 0, sizeof(map));
        
        vector< vector<data_node> > AdjList(500);
        
        
        
        for (int i=0; i<n; i++) {
            scanf("%d", &Ti[i]);
        }
        gets(line);
        for (int i=0; i<n; i++) {
            fflush(stdin);
            gets(line);
            //puts(line);
            pch = strtok (line," ");
            first_node = atoi(pch);
            
            
            pch = strtok (NULL, " ");
            
            while (pch != NULL)
            {
                second_node = atoi(pch);
                map[i][first_node] = true;
                map[i][second_node] = true;
                temp.distance = Ti[i]*(second_node-first_node);
                if (first_node == 0) {
                    temp.v = second_node+(i*100);
                    AdjList[first_node].push_back(temp);
                    temp.v = first_node;
                    AdjList[second_node+(i*100)].push_back(temp);
                }
                else{
                    temp.v = second_node+(i*100);
                    AdjList[first_node+(i*100)].push_back(temp);
                    temp.v = first_node+(i*100);
                    AdjList[second_node+(i*100)].push_back(temp);
                }
                pch = strtok (NULL, " ");
                first_node = second_node;
            }
        }
        
        for (int k=1; k<100; k++) {
            for (int i=0; i<n-1; i++) {
                for (int j=i+1; j<n; j++) {
                    if (map[i][k]==true && map[j][k]==true) {
                        int num1 = (100*i)+k;
                        int num2 = (100*j)+k;
                        temp.v = num2;
                        temp.distance = 60;
                        AdjList[num1].push_back(temp);
                        temp.v = num1;
                        AdjList[num2].push_back(temp);
                    }
                }
            }
        }
       
        
        int res = dijkstra(0, k, AdjList);
        //printf("%d\n", res);
        if (res == INF) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", res);
        }
        //printf("ih\n");
    }
    
    
    
    return 0;
}



