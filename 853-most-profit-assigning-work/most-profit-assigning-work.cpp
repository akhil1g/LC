class Solution {
public:
    int fun(vector<pair<int,int>> &nums,int x)
    {
        int n=nums.size();
        int st=0,end=n-1;
        int ans=0;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(nums[mid].first<=x)
            {
                ans=max(ans,nums[mid].second);
                st=mid+1;
            }
            else
            end=mid-1;
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
         int n=diff.size();
         vector<pair<int,int>> nums(n);
         for(int i=0;i<n;i++)
         nums[i]={diff[i],profit[i]};
         sort(nums.begin(),nums.end());
         for(int i=1;i<n;i++)
         {
            nums[i].second=max(nums[i].second,nums[i-1].second);
         }
         int ans=0;
         for(int i=0;i<worker.size();i++)
         {
            ans+=fun(nums,worker[i]);
         }
         return ans;
    }
};