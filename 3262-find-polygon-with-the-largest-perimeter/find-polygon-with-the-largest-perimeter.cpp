using ll=long long;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll c=0;
        ll ans=-1;
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        c=nums[0]+nums[1];
        for(int i=2;i<n;i++)
        {
            if(c>nums[i])
            {
                ans=max(ans,c+nums[i]);
            }
            c+=nums[i];
        }
        return ans;
    }
};