#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector< pair<int,int> > backedges;
std::vector< pair<int,int> > treeedges;
int visited[1000]={0};
std::vector<int> parent(100);
int par[100];

void dfs(vector<int> g[],int n,int i){
	int j;

	for (j=0;j<g[i].size();j++){

		if(visited[g[i][j]]==0){
			visited[g[i][j]]=1;
			treeedges.push_back(make_pair(i,g[i][j]));
			cout << g[i][j] << " ";
			
			parent[g[i][j]].push_back(i);
			par[g[i][j]]=x;
			while(par[x]!=x){
				parent[x].push_back(par[x]);
				x=par[x];
			}
			dfs(g,n,g[i][j]);

		}else{
			// if (find(parent[g[i][j]].begin(), parent[g[i][j]].end(),i)!=v.end()){
			// backedges.push_back(make_pair(i,g[i][j]));	
			// }
			// backedges.push_back(make_pair(i,g[i][j]));
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
	par[source]=source;
	cout << "DFS traversal: " << source << " " ;
	dfs(g,n,source);

	cout << "\nTREE-EDGES : \n";
	for(i=0;i<treeedges.size();i++){
		cout << treeedges[i].first << " " << treeedges[i].second << endl;
	}

	// cout << "\nBACK-EDGES : \n";
	// for(i=0;i<backedges.size();i++){
	// 	cout << backedges[i].first << " " << backedges[i].second << endl;
	// }

	for(i=0;i<n;i++){
		
	}

return 0;	
}
