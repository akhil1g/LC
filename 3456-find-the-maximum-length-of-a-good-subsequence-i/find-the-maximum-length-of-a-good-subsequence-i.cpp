class Solution {
public:
    int dp[501][502][26];
    int fun(int index,int k,int prev,vector<int> &nums)
    {
        if(index==nums.size())
            return 0;
        if(dp[index][prev][k]!=-1)
            return dp[index][prev][k];
        int tk=0,nt=0;
        if(prev==501)
        {
            tk=1+fun(index+1,k,index,nums) ;      
            nt=fun(index+1,k,prev,nums);
        }
        else
        {
            if(nums[index]!=nums[prev]&&k>0)
                tk=max(tk,1+fun(index+1,k-1,index,nums));
            else
            if(nums[index]==nums[prev])
                tk=max(tk,1+fun(index+1,k,prev,nums));
            nt=max(nt,fun(index+1,k,prev,nums));
        }
        return dp[index][prev][k]=max(tk,nt);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,k,501,nums);
    }
};