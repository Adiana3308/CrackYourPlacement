  class Solution {
public:
    int pivot(vector<int>&nums)
    {
        int s=0;
        int e = nums.size()-1;
        int mid = s+ (e-s)/2;
        while(s<e)
        {
            if(nums[mid]>=nums[0])
            {
                s = mid+1;
            }
            else
            {
                e=mid;
            }
            mid = s+(e-s)/2;
        }
        
        return s;
    }
    int binary(vector<int>&nums,int start,int end,int target)
    {
        int s = start;
        int e = end;
        int mid = s+ (e-s)/2;

        while(s<=e)
        {
            if(target == nums[mid])
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        int start = pivot(nums);
        int n=nums.size();
        if(target>=nums[start] && target<=nums[n-1])
        {
            return binary(nums,start,n-1,target);
        } 
        else
        {
            return binary(nums,0,start-1,target);
        }
    }
};
