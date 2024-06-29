class Solution {
public:
    int fun(int index,int sum,vector<int> &arr,vector<vector<int>>&dp)
    {
        if(sum==0)
        return 1;
        if(index==arr.size())
        return sum==0;
        if(dp[index][sum]!=-1)
        return dp[index][sum];
        int ans=0;
        if(arr[index]<=sum)
        {
            ans=max(ans,fun(index+1,sum-arr[index],arr,dp));
        }
        ans=max(ans,fun(index+1,sum,arr,dp));
        return dp[index][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)
        s+=nums[i];
        if(s&1)
        return false;
        s/=2;
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        return fun(0,s,nums,dp)>0;
    }
};