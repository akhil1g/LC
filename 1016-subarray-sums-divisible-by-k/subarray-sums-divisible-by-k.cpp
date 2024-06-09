class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            s%=k;
            if(s<0)
            s+=k;
            if(mp.count(s))
            {
                ans+=mp[s];
                mp[s]++;
            }
            else
            mp[s]=1;
        }
        return ans;
    }
};