//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(set<vector<int>>& ans, vector<int>& arr, int n, int index) {
    if (index >= n) {
        ans.insert(arr);  // Insert the permutation into the set
        return;
    }

    for (int j = index; j < n; j++) {
        swap(arr[index], arr[j]);
        solve(ans, arr, n, index + 1);
        swap(arr[index], arr[j]);  // Backtrack
    }
}

vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
    set<vector<int>> ans_set;
    solve(ans_set, arr, n, 0);
    
    vector<vector<int>> ans(ans_set.begin(), ans_set.end());
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
