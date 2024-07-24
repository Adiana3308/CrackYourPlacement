class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                element=nums[i];
            }
            else if(element==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<n;i++){
            if(element==nums[i]){
                count1++;
            }
        }
        if(count1>n/2){
            return element;
        }
        else{
            return -1;
        }
    }
};
