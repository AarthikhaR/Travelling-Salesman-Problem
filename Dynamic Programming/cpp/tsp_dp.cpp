#include<bits/stdc++.h>
using namespace std;
#define V 5

int tsp(int graph [][V] , int s)
{
	vector <int> vertex;
	for(int i = 0;i < V; ++i)
		if( i!= s )
			vertex.push_back(i);
		
	int min_path = INT_MAX;
	do
	{
		int path_wgt = 0;
		int k = s;
		for(int i = 0;i < vertex.size();i++)
		{
			path_wgt = path_wgt + graph [k] [vertex[i]];
			k = vertex [i];
		}
		path_wgt = path_wgt + graph [k] [s];
		min_path = min(min_path , path_wgt);
	}while (next_permutation(vertex.begin(), vertex.end()));
	return min_path;
}
int main()
{
	cout << "Program to find the minimum distance required to travel five cities in TN : \n Tiruchirapalli \n Thanjavur \n Theni \n Tiruppur \n Tirunelveli \n";
	int graph[] [V] = { {0,48,159,151,254},{48,0,201,199,276},{159,201,0,123,144},{151,199,123,0,267},{254,276,144,267,0} };
	int s = 0;
	cout << "The minimum distance it takes to travel through the above cities is "<<tsp(graph,s) << " km" << endl;
}
    

