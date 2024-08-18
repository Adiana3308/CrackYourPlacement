class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxu=0;
        int n=nums.size();
        for(int i=0;i<=maxu;i++){
            maxu = max(maxu,(nums[i]+i));
            if(maxu>=n-1){
                return true;
            }
        }
        return false;
    }
};
