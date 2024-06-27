class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i>m||j>n)
        return 0;
        if(grid[i][j]==1)
        return 0;
        if(i==m&&j==n)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down=0,right=0;
        down+=fun(i+1,j,m,n,grid,dp);
        right+=fun(i,j+1,m,n,grid,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(0,0,m-1,n-1,grid,dp);
    }
};