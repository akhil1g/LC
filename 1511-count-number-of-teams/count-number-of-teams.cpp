class Solution {
public:
    int fun(vector<int> &nums)
    {
         int ans=0;
         int n= nums.size();
        for(int i=0;i<n;i++)
        {
            int c1=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                c1++;
            }
            int c2=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                c2++;
            }
            ans+=(c1*c2);
        }
        return ans;
    }
    int numTeams(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        ans+=fun(nums);
        reverse(nums.begin(),nums.end());
        ans+=fun(nums);       
        return ans;
    }
};