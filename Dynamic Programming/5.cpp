//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int max=0;
        for(int i=0;i<str1.length();i++){
            for(int j=1;j<=str1.length()-i;j++){
                if(str2.find(str1.substr(i,j))!=-1){
                    if(j>max) max=j; 
                 }
                 else break;
        }
        }
        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
