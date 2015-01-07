class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > res(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0] == 0 )
                res[i][0]=1;
            else break;// don't forget
        }
        for(int j=0;j<n;j++)
            if(obstacleGrid[0][j] == 0)
                res[0][j]=1;
            else break;//dont forget
        
        for(int i=1;i<m;i++)
        {
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 0 )
                    res[i][j] = res[i-1][j] + res[i][j-1];
                else res[i][j] = 0;
            }
        }
        
        return res[m-1][n-1];
        
    }
};