//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow (string s, string p)
    {
        // Your code here
        if(p.length()>s.length()) return "-1";
        char temp=p[0];
        int start=0,end=0;
        vector<pair<int,int>> ans;
        for(int i=0;i<s.length()-p.length();i++){
            if(s[i]==temp) start=i;
            end=start+1;
            int m=1;
            
            while(end<s.length() && m<p.length()){
                if(s[end]==p[m]){
                    m++;
                    end++;
                }
                 end++;
                
            }
            if(m==p.length()){
                //cout<<start<<nem;
                ans.push_back({start,end});
            }
            
        }
        string fin="";
        
        if(ans.size()==0) fin+='-1';
        
        else {
            int sizer=(ans[0].second-ans[0].first);
            int ind=0;
            for(int i=ans.size()-1;i>0;i--){
                //cout<<ans[i].first<<" "<<ans[i].second;
                if(sizer>(ans[i].second-ans[i].first)){
                    sizer=(ans[i].second-ans[i].first);
                    ind=i;
                }
            }
            fin+=s.substr(ans[ind].first,ans[ind].second);
        }
        return fin;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
