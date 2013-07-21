#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

//bool visited[4][4][4][4][4][4][4][4];

/*bool get_visited(string a){
	int vals[8];
	for(int i=0; i<a.length(); i++){
		if(a[i]=='G'){
			vals[i]=0;
		}
		else if(a[i]=='R'){
			vals[i]=1;
		}
		else if(a[i]=='B'){
			vals[i]=2;
		}
		else vals[i]=3;
	}
	return visited[vals[0]][vals[1]][vals[2]][vals[3]][vals[4]][vals[5]][vals[6]][vals[7]];
}*/

/*bool set_visited(string a){
	int vals[8];
	for(int i=0; i<a.length(); i++){
		if(a[i]=='G'){
			vals[i]=0;
		}
		else if(a[i]=='R'){
			vals[i]=1;
		}
		else if(a[i]=='B'){
			vals[i]=2;
		}
		else vals[i]=3;
	}
	return (visited[vals[0]][vals[1]][vals[2]][vals[3]][vals[4]][vals[5]][vals[6]][vals[7]]=true);
}*/

int main(){
	int t;
	string f;
	string first;
	string s;
	string front;
	int cur_d;
	
	cin >> t;
	for(int x=0; x<t; x++){
		bool solved = false;
		cin >> f;
		cin >> s;
		//memset(visited, 0, sizeof(visited));
		set<string> visited;
		queue<string> next_queue;
		queue<int> depth;
		next_queue.push(f);
		visited.insert(f);
		//set_visited(f);
		depth.push(0);
		while(!next_queue.empty()){
			front = next_queue.front();
			cur_d = depth.front();
			
			if(front == s){
				solved = true;
				break;
			}
			//cout << front << endl;
			cur_d++;

			for(int i=0; i<front.length(); i++){
				if (front[i]=='B' || front[i]=='R'){
					first = front;
					if (i != first.length()-1 && first[i+1]=='.'){
						first[i+1]=first[i];
						first[i]='.';
						if(visited.find(first) == visited.end()){
							visited.insert(first);
							next_queue.push(first);
							depth.push(cur_d);
						}
						/*if(!get_visited(first)){
							set_visited(first);
							next_queue.push(first);
							depth.push(cur_d);
						}*/
					}
					first = front;
					if (i+2 < first.length() && first[i+1] != '.' && first[i+2]=='.'){
						first[i+2] = first[i];
						first[i] = '.';
						if(visited.find(first) == visited.end()){
							visited.insert(first);
							next_queue.push(first);
							depth.push(cur_d);
						}
						/*if(!get_visited(first)){
							set_visited(first);
							next_queue.push(first);
							depth.push(cur_d);
						}*/
					}
				}

				if (front[i] == 'G' || front[i]=='R'){
					first = front;
					if (i != 0 && first[i-1]=='.'){
						first[i-1]=first[i];
						first[i]='.';
						if(visited.find(first) == visited.end()){
							visited.insert(first);
							next_queue.push(first);
							depth.push(cur_d);
						}
						/*if(!get_visited(first)){
							set_visited(first);
							next_queue.push(first);
							depth.push(cur_d);
						}*/
					}
					first = front;
					if (i-2 >= 0 && first[i-1] !='.' && first[i-2]=='.'){
						first[i-2]=first[i];
						first[i]='.';
						if(visited.find(first) == visited.end()){
							visited.insert(first);
							next_queue.push(first);
							depth.push(cur_d);
						}
						/*if(!get_visited(first)){
							set_visited(first);
							next_queue.push(first);
							depth.push(cur_d);
						}*/
					}
				}

			}
			next_queue.pop();
			depth.pop();

		}
		if(solved){
			cout << "Case " << x+1 << ": " << cur_d << endl; 
		}
		else{
			cout << "Case " << x+1 << ": impossible" << endl;
		}
	}

}