class Solution {
public:
    void dfsOperation(vector<vector<int>>& image, int row, int col, int parColor, int newColor){
        if(row<0 || col < 0 || row==image.size() || col == image[0].size())
            return;
        if(image[row][col] != parColor)
            return;
        
        image[row][col] = newColor;
        
        dfsOperation(image, row, col-1, parColor, newColor);
        
        dfsOperation(image, row, col+1, parColor, newColor);
        
        dfsOperation(image, row-1, col, parColor, newColor);
        
        dfsOperation(image, row+1, col, parColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        dfsOperation(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
