using ll=long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();
        ll st=0,end=0,c=0,ans=0;
        ll mx=*max_element(nums.begin(),nums.end());
        while(end<n)
        {
            if(nums[end]==mx)
            c++;
            while(c>=k)
            {
                if(nums[st]==mx)
                c--;
                ans+=(n-end);
                st++;
            }
            end++;
        }
        return ans;
    }
};