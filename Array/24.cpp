class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int size=cardPoints.size();
        int new_j,new_i;
        int i=size-k,j=i,sum=0,ans=0;
        while(j<size+k)
        {
            new_j=j%size;
            new_i=i%size;
            sum=sum+cardPoints[new_j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                ans=max(ans,sum);
                sum=sum-cardPoints[new_i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
