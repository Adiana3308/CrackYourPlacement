class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int sC=0;
        int sR=0;
        int eC=col-1;
        int eR=row-1;
        
        int count=0;
        int total = row*col;
        
        while(count<total)
        {
//             starting row
            for(int index=sC;count<total && index<=eC;index++)
            {
                ans.push_back(matrix[sR][index]);
                count++;
            }
            sR++;
//             ending column
            for(int index=sR;count<total && index<=eR;index++)
            {
                ans.push_back(matrix[index][eC]);
                count++;
            }
            eC--;
//             ending row
            for(int index=eC;count<total && index>=sC;index--)
            {
                ans.push_back(matrix[eR][index]);
                count++;
            }
            eR--;
//             starting column
             for(int index=eR;count<total && index>=sR;index--)
            {
                ans.push_back(matrix[index][sC]);
                count++;
            }
            sC++;
        }
        return ans;
    }
};
