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
