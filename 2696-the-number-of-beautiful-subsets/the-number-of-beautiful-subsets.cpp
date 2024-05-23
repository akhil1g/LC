class Solution {
public:
    int fun(int index,vector<int> &nums,unordered_map<int,int> &mp,int k)
    {
        if(index==nums.size())
        return mp.size()>0?1:0;
        int take=0,nottake=0;
        if(mp.find(nums[index]-k)==mp.end()&&mp.find(nums[index]+k)==mp.end())
        {
            mp[nums[index]]++;
            take+=fun(index+1,nums,mp,k);
            mp[nums[index]]--;
            if(mp[nums[index]]==0)
            mp.erase(nums[index]);
        }
        nottake+=fun(index+1,nums,mp,k);
        return take+nottake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        return fun(0,nums,mp,k);
    }
};