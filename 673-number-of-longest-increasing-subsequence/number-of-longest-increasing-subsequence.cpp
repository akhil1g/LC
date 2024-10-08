class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int m=0,pos=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else
                if(nums[i]>nums[j]&&1+dp[j]==dp[i])
                count[i]+=count[j];
            }
            if(m<dp[i])
                m=dp[i];
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==m)
            c+=count[i];
        }
        return c;
    }
};