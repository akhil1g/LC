using ll=long long;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<ll,ll> m;
        ll ans=0;
        ll s=0,e=0;
        int n=nums.size();
        while(e<n)
        {
            m[nums[e]]++;
            while(m.size()&&abs(m.rbegin()->first-m.begin()->first)>limit)
            {
                m[nums[s]]--;
                if(m[nums[s]]==0)
                m.erase(nums[s]);
                s++;
            }
            ans=max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};