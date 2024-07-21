class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+nums[i];
        unordered_map<int,int> mp;
        int st=-1,end=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end()&&mp[nums[i]]>=st)
            {
                if(st==-1)
                {
                    // cout<<pref[i-1]<<"\n";
                    ans=max(ans,pref[i-1]);
                    st=mp[nums[i]]+1;
                }
                else
                {
                    // cout<<"! "<<pref[i-1]<<" "<<pref[st-1]<<" ";
                    ans=max(ans,pref[i-1]-pref[st-1]);
                    st=mp[nums[i]]+1;
                }
            }
            mp[nums[i]]=i;
        }
        if(st==-1)
        {
            return pref[n-1];
        }
        ans=max(ans,pref[n-1]-pref[st-1]);
        return ans;
    }
};