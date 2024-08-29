//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        if(V<=2) return false;
        
        vector<int> visited(V,0);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(visited[i]) continue;
            
            visited[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                int k=adj[node].size();
                bool key=false;
                for(int j=0; j<k;j++){
                    int neigh= adj[node][j];
                    if(visited[neigh]==1) continue;
                    
                    visited[neigh]
                    key=true;
                    q.push(neigh);
                }
                if(k>=2 && key==false) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
