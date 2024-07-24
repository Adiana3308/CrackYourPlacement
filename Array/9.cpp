class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(auto it:count){
            if(it.second>n/2){
                return it.first;
            }
        }
        return -1;
    }
};
