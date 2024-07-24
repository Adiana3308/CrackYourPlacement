class Solution {
public:
    string reverseWords(string s) {
        stack<string>a;
        for(int i=0;i<s.size();i++){
            string word="";

            if(s[i]==' '){
                continue;
            }
            while(s[i]!=' ' && i<s.size()){
                word+=s[i];
                i++;
            }
            a.push(word);
        }
        string ans="";
        while(!a.empty()){
            ans+=a.top();
            a.pop();
            if(!a.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};
