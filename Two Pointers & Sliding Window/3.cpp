class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int one=0;
        int zero=0;
        int two =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else if(nums[i]==1){
                one++;
            }
            else{
                two++;
            }
        }
        int i=0;
        while(zero-- && i<n){
            nums[i]=0;
            i++;
        }
        while(one-- && i<n){
            nums[i]=1;
            i++;
        }
        while(two-- && i<n){
            nums[i]=2;
            i++;
        }
        
    }
};
