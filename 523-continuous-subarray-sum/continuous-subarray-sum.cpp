class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int sum=0;
        unordered_map<int,int> m;
        int n=nums.size();
        int ans=0;
        int c=0;
        m[0]=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                c++;
                if(c>=2) return true;
            }
            else c=0;
            sum=(sum+nums[i])%k;
            if(sum==0)
            ans=max(ans,i-m[0]+1);
            if(m.find(sum)!=m.end())
                 ans=max(ans,i-m[sum]);
            if(nums[i]!=0)
            m[sum]=i;
        }
        return ans>=2? true:false;
    }
};