class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }

private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        if(row < 0 || row > grid.size() -1 || col < 0 || col > grid[0].size() - 1 || grid[row][col] == '0' || vis[row][col])
        {
            return;
        }
        vis[row][col] = 1;
        dfs(row-1,col,vis,grid);
        dfs(row+1,col,vis,grid);
        dfs(row,col-1,vis,grid);
        dfs(row,col+1,vis,grid);
    }
};
