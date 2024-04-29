class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int x=0;
        for(int i=0;i<n;i++)
            x^=nums[i];
        for(int j=0;j<31;j++)
        {
            int b1=(x&(1<<j));
            int b2=(k&(1<<j)); 
            if(b1!=b2)
                ans++;
        }
        return ans;
    }
};