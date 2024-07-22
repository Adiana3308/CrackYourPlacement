class Solution {
public:
    bool match(char top, char ch){
        if((top=='(' && ch==')')||(top=='[' && ch==']')||(top=='{' && ch=='}')){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {
        stack<char>a;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='['||ch=='{'|| ch=='('){
                a.push(ch);
            }
            else{
                if(!a.empty()){
                    char top = a.top();
                    if(match(top,ch)){
                        a.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(a.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};
