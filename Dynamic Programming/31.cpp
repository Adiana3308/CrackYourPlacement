//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int i,int t,int arr[],vector<vector<int>> &dp){
        if(t==0)
            return 1;
        if(i<0)
            return 0;
        
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        int take=(arr[i]<=t)?fun(i-1,t-arr[i],arr,dp):0;
        int notTake=fun(i-1,t,arr,dp);
    
        return dp[i][t]=take || notTake;
        
    }
    
    
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
    
        if(sum&1)
            return 0;
        int target=sum/2;    
    
        vector<vector<int>> dp(N+1,vector<int>(target+1,-1)); 
        
        return fun(N-1,target,arr,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
