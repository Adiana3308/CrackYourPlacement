class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
             vector<vector<int> >ans;
        int sC=0;
        int sR=0;
        int eR=matrix.size()-1;
        int eC=matrix.size()-1;
        
        for(int col=sC;col<=eC;col++)
        {
            vector<int>ansRow;
            for(int row=eR;row>=0;row--)
            {
                ansRow.push_back(matrix[row][col]);
            }
            ans.push_back(ansRow);
        }
        matrix=ans;
    }
};
