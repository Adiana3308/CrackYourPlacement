class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=nums.size();
        for(int a=0;a<j;a++)
        {
            if(nums[i]!=nums[a])
            {
                i++;
                nums[i]=nums[a];
            }
        }
        
        return i+1;
    }
};
