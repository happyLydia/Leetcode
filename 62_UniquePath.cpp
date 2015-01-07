class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int** p = new int*[m+1];
        for(int i=0;i<m+1;i++)
            p[i] = new int[n+1];
        
        for(int i=1;i<m+1;i++){
            p[i][1]=1;
            p[i][0]=0;
        }
        for(int j=1;j<n+1;j++){
            p[1][j]=1;
            p[0][j]=0;
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
               p[i][j] = p[i-1][j]+p[i][j-1]; 
            }
        }
        
        int res = p[m][n];
        
        for(int i=0;i<m+1;i++)
            delete[] p[i];
        delete []p;
        
        return res;
    }
};