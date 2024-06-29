class Solution {
public:
    	int mod=1e9+7;
	int fun(int index,int sum,int n,vector<int> &arr,vector<vector<int>>&dp)
    {
        if(index==n)
        return sum==0;
        if(dp[index][sum]!=-1)
        return dp[index][sum];
        int tk=0,nt=0;
        if(arr[index]<=sum)
        {
            tk=(tk+fun(index,sum-arr[index],n,arr,dp));
        }
        nt=(nt+fun(index+1,sum,n,arr,dp));
        return dp[index][sum]=(tk+nt);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return fun(0,amount,n,coins,dp);
    }
};