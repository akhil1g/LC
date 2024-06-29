class Solution {
public:
    int fun(int index,int s,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(s==0)
        return 0;
        if(index<0)
        {
            if(s==0)
            return 0;
            return 1e6;
        }
        if(dp[index][s]!=-1)
        return dp[index][s];
        int tk=1e9,nt=1e9;
        if(nums[index]<=s)
        {
            tk=min(tk,1+fun(index,s-nums[index],nums,dp));
        }
        nt=min(nt,fun(index-1,s,nums,dp));
        return dp[index][s]=min(tk,nt);

    }
    int coinChange(vector<int>& coins, int amt) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        int ans=fun(n-1,amt,coins,dp);
        if(ans>=1e6)
        return -1;
        return ans;

    }
};