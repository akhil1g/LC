class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i>=m||j>=n)
        return 1e8;
        if(i==m-1&&j==n-1)
        return grid[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down=1e9,right=1e9;
        down=min(down,grid[i][j]+fun(i+1,j,m,n,grid,dp));
        right=min(right,grid[i][j]+fun(i,j+1,m,n,grid,dp));
        // cout<<i<<" "<<j<<" "<<down<<" "<<right<<"\n";
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(0,0,m,n,grid,dp);
    }
};