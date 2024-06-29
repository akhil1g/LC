class Solution {
public:
    	int mod=1e9+7;
	int fun(int index,int sum,int n,vector<int> &arr,map<int,map<int,int>> &mp)
    {
        if(index==n)
        return sum==0;
        if(mp.find(index)!=mp.end()&&mp[index].find(sum)!=mp[index].end())
        {
            return mp[index][sum];
        }
        // if(dp[index][sum]!=-1)
        // return dp[index][sum];
        int tk=0,nt=0;
        if(arr[index]<=sum)
        {
            tk=(tk+fun(index+1,sum-arr[index],n,arr,mp)%mod)%mod;
        }
        nt=(nt+fun(index+1,sum,n,arr,mp)%mod)%mod;
        return mp[index][sum]=(tk+nt)%mod;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        s+=nums[i];
        // s1+s2=s;
        // s1-s2=target;
        if((s+target)%2==1)
        return 0;
        int s1=(s+target)/2;
        map<int,map<int,int>> dp;
        return fun(0,s1,n,nums,dp);
    }
};