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



struct rectangle{
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
};


struct point{
	int x, y;
	int id;
};

int main() {

	int N;
	cin >> N;
	rectangle rectangles[5];
	map<int, vector<int> > all_ys;
	map<int, vector<int> > all_xs;

	int furthest_left = (1<<30);
	int furthest_right = -(1<<30);
	int furthest_up = -(1<<30);
	int furthest_down = (1<<30);

	vector<point> points;
	point tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> rectangles[i].x1 >> rectangles[i].y1  >> rectangles[i].x2 >> rectangles[i].y2;
		rectangles[i].x3 = rectangles[i].x1;
		rectangles[i].y3 = rectangles[i].y2;
		rectangles[i].x4 = rectangles[i].x2;
		rectangles[i].y4 = rectangles[i].y1;
		tmp.id = i;

		tmp.x = rectangles[i].x1;
		tmp.y = rectangles[i].y1;
		points.push_back(tmp);

		tmp.x = rectangles[i].x2;
		tmp.y = rectangles[i].y2;
		points.push_back(tmp);

		tmp.x = rectangles[i].x3;
		tmp.y = rectangles[i].y3;
		points.push_back(tmp);

		tmp.x = rectangles[i].x4;
		tmp.y = rectangles[i].y4;
		points.push_back(tmp);


		if(rectangles[i].x1 < furthest_left){
			furthest_left = rectangles[i].x1;
		}
		if(rectangles[i].x2 > furthest_right){
			furthest_right = rectangles[i].x2;
		}
		if(rectangles[i].y1 < furthest_down){
			furthest_down = rectangles[i].y1;
		}
		if(rectangles[i].y2 > furthest_up){
			furthest_up = rectangles[i].y2;
		}

	}
	bool collided = true;
	for(int i=0; i<points.size(); i++){
		int colls = 0;
		for(int j=0; j<N; j++){
			if( (points[i].x == furthest_left && (points[i].y == furthest_up || points[i].y==furthest_down ) ) || (points[i].x == furthest_right  && (points[i].y == furthest_up || points[i].y==furthest_down ) )  ){
				colls++;
			}
			else{
				if(j != points[i].id){
					if(points[i].x == rectangles[i].x1 && rectangles[i].y3 >= points[i].y && rectangles[i].y1 <= points[i].y ){
						colls++;
					}
					if(points[i].x == rectangles[i].x2 && rectangles[i].y3 >= points[i].y && rectangles[i].y1 <= points[i].y ){
						colls++;
					}
					if(points[i].y == rectangles[i].y1 && rectangles[i].x1 <= points[i].x && rectangles[i].x2 >= points[i].x ){
						colls++;
					}
					if(points[i].y == rectangles[i].y2 && rectangles[i].x1 <= points[i].x && rectangles[i].x2 >= points[i].x ){
						colls++;
					}												
				}
			}
		}
		if(colls == 0){
			collided = false;
			break;
		}

	}
	if(!collided){
		cout << "NO"<<endl;
	}
	else cout << "YES" << endl;




	
	return 0;
}