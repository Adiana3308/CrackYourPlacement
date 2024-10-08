//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef vector<int> vi;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<vi, vector<vi>, greater<vi>> pq; // weight, node, parent
        vi vis(V,0); // visited array
        pq.push({0, 0, -1});
        int sum = 0;
        // vector<pair<int, int>> mst;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it[0] , node =it[1] , parent= it[2];
            if(vis[node]) continue;
            vis[node]=1;
            sum += wt;
            // if(parent !=-1) mst.push_back({node, parent});
            for(auto i : adj[node]){
                int adjnode = i[0], adjwt = i[1];
                if(!vis[adjnode]){
                    pq.push({adjwt, adjnode, node});
                }
            }
            
            
        }

        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
