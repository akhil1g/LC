class Solution {
public:
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
        cout<<"\n";
        int st=0;
        int end=1e9;
        int ans=0;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            // cout<<mid<<' ';
            int c=1;
            int pos=nums[0];
            bool f=true;
            for(int i=1;i<n;i++)
            {
                // if(c>m+1)
                // {
                //     f=false;
                //     break;
                // }
                if(nums[i]-pos>=mid)
                {
                    c++;
                    pos=nums[i];
                }
            }
            cout<<mid<<" "<<c<<"\n";
            if(!f)
            {
                st=mid+1;
            }
            else
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