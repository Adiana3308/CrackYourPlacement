//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	     vector<int> adj[N];
         vector<int> InDeg(N,0);
         for(int i=0;i<P;i++)
         {
             adj[prerequisites[i].second].push_back(prerequisites[i].first);
             InDeg[prerequisites[i].first]++;
             
         }
         queue<int>q;
         for(int i=0;i<N;i++)
         {
             if(!InDeg[i])
             q.push(i);
         }
         int count = 0;
         while(!q.empty())
         {
             int Node = q.front();
             q.pop();
             count++;
             for(int j=0;j<adj[Node].size();j++)
             {
                InDeg[adj[Node][j]]--;
                if(InDeg[adj[Node][j]]==0)
                q.push(adj[Node][j]);
             }
         }
         return count==N?1:0;
    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
