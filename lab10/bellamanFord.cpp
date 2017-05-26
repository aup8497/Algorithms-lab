#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long 
ll n,m,i,j,k,w,x,y,count;

int main(){

	cout << "enter the number of nodes and edges" << endl;
	cin >> n >> m;
	cout << "enter the graph(1 based) v1 v2 w"<< endl;
	std::vector< pair< int,pair<int,int> > > e;
	int dist[n];

	for (i = 0; i < m; ++i){
		cin >> x >> y >> w ;	
		e.pb( mp( w,mp(x,y) ) );
	}

	for (i = 0; i < m; ++i){
		cout << e[i].first << e[i].second.first << e[i].second.second ;
	}

	cout << "enter the source " <<endl;
	cin >> x;
	//allocationg the distance of the source to be zero.
	for(i=0;i<n;i++){
		if(i==x)
			dist[i]=0;
		else
			dist[i]=9999;
	}

	//initialsizing all weights to inf
	for(count=0;count<n-1;count++){
		for(i=0;i<m;i++){
			dist[e[i].second.second]=min( dist[e[i].second.second] , e[i].second.first+e[i].first );
		}
	}

	cout<< " the final distances from each nodes are "; 
	for(i=0;i<n;i++){
		cout << dist[i] << " " << endl;
	}

return 0;	
}
