class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1,c=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(c==0)
            {
                ele=nums[i];
                c=1;
            }
            else 
            if(ele==nums[i]) 
            c++;
            else
            c--;
            // cout<<i<<" "<<c<<" "<<ele<<"\n";
        }
        // cout<<c<<" "<<ele<<"\n";
        int c1=0;
        for(int i=0;i<n;i++)
        if(nums[i]==ele) c1++;
        return c1>n/2?ele:-1;
    }
};