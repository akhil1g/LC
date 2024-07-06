class Solution {
public:
    int n;
    int fun(int index,int prev,vector<int> &nums,vector<int> &temp)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(nums[i]);
            }
            else
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[index]=nums[i];
            }
        }
        return temp.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<int> temp;
        return fun(0,n,nums,temp);
    }
};