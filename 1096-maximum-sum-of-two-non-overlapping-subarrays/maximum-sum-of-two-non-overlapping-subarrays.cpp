class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int l) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        if(f<l)
        swap(f,l);
        for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+nums[i];
        int ans=0;
        for(int i=0;i<=n-f;i++)
        {
            int t1=0;
            if(i==0)
                t1=pref[f-1];
            else
                t1=pref[i+f-1]-pref[i-1];
            int t2=0;
            for(int j=0;j<=i-l;j++)
            {
                if(j==0)
                    t2=pref[l-1];
                else
                    t2=max(t2,pref[j+l-1]-pref[j-1]);
            }
            for(int j=i+f+1;j<=n-l;j++)
            {
                t2=max(t2,pref[j+l-1]-pref[j-1]);
                cout<<t2<<" ";
            }
            ans=max(ans,t1+t2);
        }
        return ans;
    }
};