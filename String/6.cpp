class Solution {
public:

bool check(string s, int low, int high){
    while(low<=high){
        if(s[low]!=s[high])return false;
        low++; high--;
    }
    return true;
}

// start
    bool validPalindrome(string s){
        int count = 0;
        int n = s.size();
        int low = 0, high = n-1;
        while(low<=high){
            // if low and high element is equal then move on
            if(s[low]==s[high]){
                low++; high--;
            }
            // if not equal then pass the function in check
            /* we will pass 2 value in check, one after deleting
               low and another after deliting high.
            -> if any of the passed value returns true, then 
               it is a valid palindrome */
            else{
                return (check(s, low+1, high) || check(s, low, high-1));
            }
        }
        // if while lowop se koi return nhi aaya then
        return true;
    }
};
