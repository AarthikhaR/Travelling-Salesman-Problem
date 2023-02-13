#include <iostream>
using namespace std;

#define INT_MAX 999999

int n = 4;

int dist[10][10] = {
				{0,48,159,151,254},
				{48,0,201,199,276},
				{159,201,0,123,144},
				{151,199,123,0,267},
				{254,276,144,267,0}
				   };

int VISITED_ALL = (1<<n) - 1;

int tsp(int mask , int pos)
{
	if(mask == VISITED_ALL)
		return dist[pos][0];
	int ans = INT_MAX;
	for(int city = 0;city < n;city++)
	{
		if((mask & (1<<city)) == 0)
		{
			int newAns = dist[pos][city] + tsp( mask | (1<<city),city);
			ans = min(ans,newAns);
		}
	}
	return ans;
}
int main()
{
	cout << "Program to find the minimum distance required to travel five cities in TN : \n Tiruchirapalli \n Thanjavur \n Theni \n Tiruppur \n Tirunelveli \n";
	cout<<"Minimun distance it takes to travel through the above cities are = "<<tsp(1,0) << " km"<<endl;
	return 0;	
}
