class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<int> bits(31,0);
        int x=0;
        for(int i=0;i<n;i++)
        {
            x^=nums[i];
        }
        for(int j=0;j<31;j++)
        {
            int b1=(x&(1<<j));
                int b2=(k&(1<<j)); 
            if(b1!=b2)
            {
                ans++;
            }
        }
        return ans;
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            for(int j=0;j<31;j++)
            {
                int b1=(ele&(1<<j));
                int b2=(k&(1<<j));
                if(b2==1)
                {
                    if(b1==0)
                    {
                        ans++;
                    }
                }
                else
                {
                    if(b1==1)
                    {
                        if(bits[j]==1)
                        {
                            continue;
                        }
                        else
                        {
                            ans++;

                        }
                    }
                }
            }
        }
    }
};