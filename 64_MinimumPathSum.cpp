class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>gsum(m,vector<int>(n));
        
        gsum[0][0] = grid[0][0];
        
        for(int i=1; i<m;i++)
        {
            gsum[i][0] = gsum[i-1][0]+grid[i][0];
        }
        
        for(int j=1;j<n;j++)
        {
            gsum[0][j] = gsum[0][j-1]+grid[0][j];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1; j<n;j++)
            {
                gsum[i][j] = min(gsum[i-1][j],gsum[i][j-1]) + grid[i][j];
            }
        }
        
        return gsum[m-1][n-1];
        
    }
};