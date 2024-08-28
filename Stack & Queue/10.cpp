//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
   int celebrity(vector<vector<int>>& mat) {
        vector<int> rowSum(mat.size(), 0), colSum(mat.size(), 0);
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                rowSum[i] += mat[j][i];
                colSum[i] += mat[i][j];
            }
        }
        for(int i = 0; i < mat.size(); i++) {
            if(rowSum[i] == mat.size() - 1 and colSum[i] == 0) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
