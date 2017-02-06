#include <iostream>
#include <vector>

using namespace std;

std::vector< pair<int,int> > backedges;
std::vector< pair<int,int> > treeedges;
int visited[1000]={0};

void dfs(vector<int> g[],int n,int i){
	int j;

	for (j=0;j<g[i].size();j++){

		if(visited[g[i][j]]==0){
			visited[g[i][j]]=1;
			treeedges.push_back(make_pair(i,g[i][j]));
			cout << g[i][j] << " ";
			dfs(g,n,g[i][j]);

			// cout << "cam here when i=" << i << " and j= "<< j ;
		}else{
			backedges.push_back(make_pair(i,g[i][j]));
		}
	}

}


int main(){

	int n,a,b,i,j,m;

	cout << "enter the number of nodes" << endl;
	cin >> n ;
	std::vector<int> g[n];
	cout << "enter the number of edges" << endl;
	cin >> m;
	cout << "enter the edges\n";
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		g[a].push_back(b);
	}
	int source;
	cout << "enter the source\n";
	cin >> source ;
	visited[source]=1;
	cout << "DFS traversal: " << source << " " ;
	dfs(g,n,source);

	cout << "\nTREE-EDGES : \n";
	for(i=0;i<treeedges.size();i++){
		cout << treeedges[i].first << " " << treeedges[i].second << endl;
	}

	cout << "\nBACK-EDGES : \n";
	for(i=0;i<backedges.size();i++){
		cout << backedges[i].first << " " << backedges[i].second << endl;
	}
return 0;	
}
