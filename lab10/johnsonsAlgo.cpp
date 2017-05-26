#include <stdio.h>
#include <iostream>
using namespace std;

ll n,m,i,j,k;

int main(){


	cout << "enter the number of nodes and edges" << endl;
	cin >> n >> e;
	cout << "enter the graph(1 based) v1 v2 w"<< endl;
	std::vector< pair<int,int> > v[n+1];

	int dist[n+1]={0};


	for(i=0;i<e;i++){
		cin >> x>> y >> w;
		v[x].push_back(make_pair(y,w));
	}
	
	for(i=1;i<=n;i++){
		v[0].push_back(make_pair(i,0));
	}

	//initialsizing all weights to zero from added extra source(tmporary)
	
	for(i=0;i<=n;i++){
		
	}

return 0;	
}
