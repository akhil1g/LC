class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        unordered_map<int,int> mp;
        int s=0,end=0;
        while(end<n)
        {
            int x=nums[end];
            set<int> st;
            bool f=true;
            for(int j=0;j<32;j++)
            {
                if((x&(1<<j))&&(mp.find(j)!=mp.end()))
                {
                    st.insert(j);
                }
            }
            while(st.size())
            {
                int m=nums[s];
                for(int j=0;j<32;j++)
                {
                    if(m&(1<<j))
                    {
                        mp[j]--;
                        if(mp[j]==0)
                        {
                            mp.erase(j);
                            if(st.find(j)!=st.end())
                            {
                                st.erase(j);
                            }
                        }
                    }
                }
                s++;
            }
            ans=max(ans,end-s+1);
            for(int j=0;j<32;j++)
            {
                if(x&(1<<j))
                {
                    mp[j]++;
                }
            }
            end++;
        }
        return ans;        
    }
};