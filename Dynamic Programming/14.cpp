//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
     int dp[10001];
    int rec(int n,vector<int>&arr){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int temp=INT_MIN;
        for(int i=0;i<3;++i){
            temp=max(temp,1+rec(n-arr[i],arr));
        }
        return dp[n]=temp;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        vector<int>arr={x,y,z};
        int ans=rec(n,arr);
        return ans<0?0:ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
