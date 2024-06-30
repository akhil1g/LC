class Solution {
public:
     int fun(int index,int buy,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        return dp[index][buy];
        int profit=0;
        if(buy==0)
        {
            profit=max(fun(index+1,1,nums,dp)-nums[index],fun(index+1,0,nums,dp));
        }
        else
        {
            profit=max(fun(index+2,0,nums,dp)+nums[index],fun(index+1,1,nums,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,0,nums,dp);
    }
};