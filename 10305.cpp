//uva 10305 Ordering Tasks
// author: Naimul Haque
//Explanation: https://youtu.be/eC1_SGrFsdU

#include <iostream>
#include <vector>
 
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sorting;
 
void dfs(int u){
    visited[u] = true;
 
    for(unsigned i = 0; i < adj[u].size(); i++) if(!visited[adj[u][i]]) dfs(adj[u][i]);
    sorting.push_back(u);
}
int main() {
	int n,m,u,v;
 
	while(cin >> n >> m,m!=0 || n!=0){
	    visited.clear();
        visited.assign(n+1, false);
 
        adj.clear();
        adj.resize(n+1);
 
        sorting.clear();
 
        while(m--) {                    
            cin >> u >> v;
            adj[u].push_back(v);
        }
 
        for(int i = 1; i <= n; ++i) if(!visited[i]) dfs(i);
 
        for(int i = n-1; i >= 0; --i){
            cout << sorting[i];
            if(i) cout << ' ';
        } 
	    cout <<'\n';
 
	}
 
 
	return 0;
}
