//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> nextSmaller(int arr[], int n) {
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--) {
            while(st.top()!=-1 && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(int arr[], int n) {
        stack<int>st;
         st.push(-1);
         vector<int>ans(n);
        for(int i=0;i<n;i++) {
            while(st.top()!=-1 && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int>next(n);
        next=nextSmaller(arr,n);
        vector<int>prev(n);
        prev=prevSmaller(arr,n);
        vector<int>ans(n+1);
        for(int i=0;i<n;i++) {
            if(next[i]==-1) {
                next[i] = n;
            }
            int len = next[i]-prev[i]-1;
            ans[len] = max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=1;i--) {
            ans[i] = max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
