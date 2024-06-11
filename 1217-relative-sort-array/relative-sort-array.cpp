class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int j=0;
        int m=arr2.size();
        unordered_map<int,int> mp;
        map<int,int> mp1;
        for(int i=0;i<m;i++)
        mp[arr2[i]]=i;
        for(int i=0;i<n;i++)
        {
            mp1[arr1[i]]++;
        }
        int k=0;
        vector<int> ans(n,0);
        for(int i=0;i<m;i++)
        {
            if(mp1.count(arr2[i]))
            {
                int freq=mp1[arr2[i]];
                while(freq--)
                {
                    ans[k]=arr2[i];
                    k++;
                }
            }
        }
        auto it=mp1.begin();
        while(it!=mp1.end())
        {
            if(mp.find(it->first)==mp.end())
            {
                int freq=it->second;
                while(freq--)
                {
                    ans[k]=it->first;
                    k++;
                }
            }
            it++;
        }
        return ans;


        
    }
};