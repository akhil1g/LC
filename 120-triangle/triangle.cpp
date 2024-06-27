class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &nums,vector<vector<int>> &dp)
    {
        if(i>=nums.size()||j>=nums[i].size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down=nums[i][j]+fun(i+1,j,nums,dp);
        int right=nums[i][j]+fun(i+1,j+1,nums,dp);
        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,nums,dp);
    }
};