class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(j>=grid[i].size()||j<0)
        return 1e9;
        if(i==grid.size()-1)
        return grid[i][j];
        if(dp[i][j]!=-1000)
        return dp[i][j];
        int down=grid[i][j]+fun(i+1,j,grid,dp);
        int right=grid[i][j]+fun(i+1,j+1,grid,dp);
        int left=grid[i][j]+fun(i+1,j-1,grid,dp);
        return dp[i][j]=min(down,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=1e9;
        vector<vector<int>> dp(n,vector<int>(m,-1000));
        for(int j=0;j<m;j++)
        {
            ans=min(ans,fun(0,j,grid,dp));
        }
        return ans;
    }
};