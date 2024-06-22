class Solution {
public:
    int fun(vector<int> &nums,int k)
    {
        int c=0,start=0,end=0,ans=0;
        for(;end<nums.size();end++)
        {
            if(nums[end]&1)
            c++;
            while(c>k&&start<=end)
            {
                if(nums[start]&1)
                c--;
                start++;
            }
            ans+=(end-start+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
     return fun(nums,k)-fun(nums,k-1);   
    }
};