class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> count(n+1);
        
        for(auto x : nums) count[x] += x;

        for(int i = 2; i <= n; i++) 
            count[i] = max(count[i] + count[i - 2], count[i - 1]);
        
        return count[n];
    }
};
