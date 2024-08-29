//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
      bool checkCycleDFS(int node , unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,vector<int> adj[])
   { 
       visited[node ]=true;
       dfsVisited[node]=true;
       
       for(auto nbr:adj[node])
       {
           if(!visited[nbr])
           {
               bool cycledetect=checkCycleDFS(nbr,visited,dfsVisited,adj);
               if(cycledetect)
               {
                   return true;
               }
           }
            else if(dfsVisited[nbr])
            {
                   //visited true;
                   return true;
            }
        }
           dfsVisited[node]=false;
           return false;
       }
    bool isCyclic(int V, vector<int> adj[]) {
        //create visited map
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        
        for(int i = 0 ; i <V ;i++)
        {
            if(!visited[i])
            {
                bool cycleFound = checkCycleDFS(i , visited , dfsVisited, adj);
                if(cycleFound)return true;
            }
        }
        return false;
    
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
