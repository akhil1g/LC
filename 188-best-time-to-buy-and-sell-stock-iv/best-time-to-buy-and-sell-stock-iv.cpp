class Solution {
public:
      int fun(int index,int buy,int k,vector<int> &nums,vector<vector<vector<int>>> &dp)
    {
        if(index==nums.size()||k<=0)
        {
            return 0;
        }
        if(dp[index][buy][k]!=-1)
        return dp[index][buy][k];
        int profit=0;
        if(buy==0)
        {
            profit=max(fun(index+1,1,k,nums,dp)-nums[index],fun(index+1,0,k,nums,dp));
        }
        else
        {
            profit=max(fun(index+1,0,k-1,nums,dp)+nums[index],fun(index+1,1,k,nums,dp));
        }
        return dp[index][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,0,k,nums,dp);
    }
};