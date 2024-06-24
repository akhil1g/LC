using ll=long long;
class Solution {
public:
    ll fun(ll index,ll prev,vector<int> &nums,vector<vector<ll>> &dp)
    {
        if(index==nums.size())
        return 0;
        if(dp[index][prev]!=-1)
        return dp[index][prev];
        ll ans=-1e9;
        if(prev==0)
        {
            ans=max(ans,nums[index]+fun(index+1,0,nums,dp));
            ans=max(ans,nums[index]+fun(index+1,1,nums,dp));
        }
        else
        {
            ans=max(ans,fun(index+1,0,nums,dp)-nums[index]);
        }
        return dp[index][prev]=ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        ll n=nums.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return fun(0,0,nums,dp);
    }
};