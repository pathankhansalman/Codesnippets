#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int p[4][2];
	int flag2 = 0, flag3 = 0, flag4 = 0;

	for(int i = 0;i<4;i++) cin>>p[i][0]>>p[i][1];

	float dist12 = sqrt(pow(p[0][0] - p[1][0],2) + pow(p[0][1] - p[1][1],2));
	float dist13 = sqrt(pow(p[0][0] - p[2][0],2) + pow(p[0][1] - p[2][1],2));
	float dist14 = sqrt(pow(p[0][0] - p[3][0],2) + pow(p[0][1] - p[3][1],2));

	if(dist12 == dist13) flag4 = 1;
	else if(dist12 == dist14) flag3 = 1;
	else flag2 = 1;

	cout<<flag2<<flag3<<flag4<<endl;

	if(!((flag2 && !(flag3 || flag4)) || (flag3 && !(flag4 || flag2)) || (flag4 && !(flag2 || flag3)))) cout<<"NO"<<endl;

	else if(!((flag2 && (dist12 > dist13)) || (flag3 && (dist13 > dist14)) || (flag4 && (dist14 > dist13)))) cout<<"NO"<<endl;

	else if(!((flag2 && p[0][0] + p[1][0] == p[3][0] + p[2][0] && p[0][1] + p[1][1] == p[2][1] + p[3][1]) 
		|| (flag3 && p[0][0] + p[2][0] == p[3][0] + p[1][0] && p[0][1] + p[2][1] == p[1][1] + p[3][1])
		|| (flag4 && p[0][0] + p[3][0] == p[1][0] + p[2][0] && p[0][1] + p[3][1] == p[2][1] + p[1][1]))) cout<<"NO"<<endl;

	else if(!(((flag2 && ((p[0][0] == p[2][0] && p[2][1] == p[1][1]) 
		|| (((p[1][1] - p[2][1])*(p[2][1] - p[0][1]))/((p[1][0] - p[2][0])*(p[2][0] - p[0][0])) == -1))))
		|| ((flag3 && ((p[0][0] == p[1][0] && p[2][1] == p[1][1]) 
		|| (((p[1][1] - p[2][1])*(p[1][1] - p[0][1]))/((p[1][0] - p[2][0])*(p[1][0] - p[0][0])) == -1))))
		|| ((flag4 && ((p[0][0] == p[1][0] && p[3][1] == p[1][1]) 
		|| (((p[3][1] - p[2][1])*(p[2][1] - p[0][1]))/((p[3][0] - p[2][0])*(p[2][0] - p[0][0])) == -1)))))) cout<<"NO"<<endl;

	else cout<<"YES"<<endl;

	return 0;
}