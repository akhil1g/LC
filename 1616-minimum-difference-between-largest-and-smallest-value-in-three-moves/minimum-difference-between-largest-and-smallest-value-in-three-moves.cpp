class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<=4)
        return 0;
        int ans=INT_MAX;
        int s=3,end=n-1;
        while(s>=0)
        {
            ans=min(ans,nums[end]-nums[s]);
            s--;
            end--;
        }
        return ans;    
    }
};