int Solution::solve(vector<int> &nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int fo= -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        else if(nums[mid]==nums[mid-1]){
            fo = mid-1;
        }
        else{
            fo = mid;
        }

        if(fo%2==0){
            low = fo + 2;
        }
        else{
            high = fo-1;
        }
    }
    return -1;
}
