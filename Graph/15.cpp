//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
     void tp(int i,vector<vector<int>> &adj,stack<int> &s,vector<bool> &visited){
        visited[i]=true;
        for(auto z:adj[i]){
            if(!visited[z])
                tp(z,adj,s,visited);
        }
        
        s.push(i);
        return;
        
    }
    
    void fun(int i,vector<int> new_adj[],vector<bool> &vis){
        vis[i]=true;
        for(auto x:new_adj[i]){
            if(!vis[x])
                fun(x,new_adj,vis);
        }
        return;
    }
    

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        //code here
        stack<int> s;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
                tp(i,adj,s,visited);
            
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        vector<int> new_adj[V];
        
        for(int i=0;i<V;i++){
            for(auto z:adj[i]){
                new_adj[z].push_back(i);
            }
            
        }

        int res=0;
        vector<bool> vis(V,false);
        
        for(int i=0;i<ans.size();i++){
            if(!vis[ans[i]]){
                res++;
                fun(ans[i],new_adj,vis);
            }
            
        }
        return res;
    }


};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
