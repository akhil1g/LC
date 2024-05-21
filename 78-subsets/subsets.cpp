class Solution {
public:
   vector<vector<int>> ans;
   void subs(vector<int> &nums,int i,vector<int> &out)
   {
       if(i>=nums.size())
       {
           ans.push_back(out);
           return;
       }
       out.push_back( nums[i]);
       subs(nums,i+1,out);
       out.pop_back();
       subs(nums,i+1,out);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> out;
        subs(nums,0,out);
        return ans;
    }
};