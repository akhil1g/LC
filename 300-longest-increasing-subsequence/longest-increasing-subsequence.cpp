class Solution {
public:
    int n;
    int fun(int index,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(index==nums.size())
        return 0;
        if(dp[index][prev]!=-1)
        return dp[index][prev];
        int tk=0,nt=0;
        if(prev==n||nums[index]>nums[prev])
        {
            tk=max(tk,1+fun(index+1,index,nums,dp));
        }
        nt=max(nt,fun(index+1,prev,nums,dp));
        return dp[index][prev]=max(tk,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(0,n,nums,dp);
    }
};