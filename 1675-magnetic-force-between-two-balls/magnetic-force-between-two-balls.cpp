class Solution {
public:
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int st=0;
        int end=1e9;
        int ans=0;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            int c=1;
            int pos=nums[0];
            for(int i=1;i<n;i++)
            {
                if(nums[i]-pos>=mid)
                {
                    c++;
                    pos=nums[i];
                }
            }
            if(c<m)
            {
                end=mid-1;
            }
            else
            {
                ans=max(ans,mid);
                st=mid+1;
            }
        }
        return ans;
    }
};