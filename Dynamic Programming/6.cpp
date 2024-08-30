//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solveRec(vector<vector<int> > &keypad,int n,int i,int j,vector<vector<vector<long long> > > &dp){


        if(i<0 || i>=keypad.size() || j<0 || j>=keypad[0].size() || keypad[i][j]==-1){
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        if(dp[n][i][j]!=-1){
            return dp[n][i][j];
        }
        
            long long same= solveRec(keypad,n-1,i,j,dp);
            
            long long up= solveRec(keypad,n-1,i-1,j,dp);
            
            long long down= solveRec(keypad,n-1,i+1,j,dp);
            
            long long left= solveRec(keypad,n-1,i,j-1,dp);
            
            long long right= solveRec(keypad,n-1,i,j+1,dp);
            
            
            return dp[n][i][j]=same+up+down+left+right;
    }

 


    
    long long getCount(int n) {
     
        vector<vector<int> > keypad={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        
        vector<vector<vector<long long> > > dp(n+1,vector<vector<long long> >(5,vector<long long>(4,-1)));
        
        long long count=0;


        for(int i=0;i<keypad.size();i++){
            for(int j=0;j<keypad[0].size();j++){
                if(keypad[i][j]!=-1){
                   count+=solveRec(keypad,n,i,j,dp);  
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
