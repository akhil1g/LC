class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(bloomDay.size()<m*k) return -1;
        int si=0;
        int ei=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        while(si<=ei)
        {
            int mid=si+(ei-si)/2;
            int j=0,c=0;
            int temp=0;
            int maxd=INT_MIN;
            int f=0;
            while(j<bloomDay.size())
            {
               if(bloomDay[j]<=mid)   c++;
               else  c=0;
               if(c==k)
               {
                   temp++;
                   c=0;
               }
               j++;
               if(temp>m) break;
            }
            if(temp<m)
            si=mid+1;
            else
            {
                ans=min(ans,mid);
                ei=mid-1;
            }
        }
        return ans!=INT_MAX?ans:-1;
    }
};