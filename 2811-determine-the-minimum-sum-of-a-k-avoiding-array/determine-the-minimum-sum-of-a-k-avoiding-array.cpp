class Solution {
public:
    int minimumSum(int n, int k) {
        map<int,int> mp;
        for(int i=1;i<=k/2;i++)
        {
            if(i!=k-i)
            mp[k-i]++;
        }
        int s=0,i=1;
        int c=0;
        while(c<n)
        {
            if(mp[i]>0)
            ;
            else
            {
                // cout<<i<<" ";
                s+=i;
                c++;
            }
            i++;
        }
        return s;
    }
};