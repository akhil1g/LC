class Solution {
public:
    int fun(vector<int> &arr,int k)
    {
        int start=0,end=0,n=arr.size(),ans=0;
        int d=0;
        unordered_map<int,int> m;
        for(;end<n;end++)
        {
            if(m[arr[end]]==0)
            d++;
            m[arr[end]]++;
            while(d>k)
            {
                m[arr[start]]--;
                if(m[arr[start]]==0)
                d--;
                start++;
            }
            ans+=(end-start+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};