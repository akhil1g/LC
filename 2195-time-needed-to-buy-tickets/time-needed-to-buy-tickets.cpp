class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,num=nums[k];
        int s=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<num)
            {
                ans+=nums[i];
            }
            else
            {
                c++;
            }
        }
        ans+=(c*(num-1));
        for(int i=0;i<=k;i++)
        {
            if(nums[i]>=num)
            ans++;
        }
        return ans;


    }
};