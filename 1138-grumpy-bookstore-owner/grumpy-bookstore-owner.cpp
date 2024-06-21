class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int mins) {
        int n=cust.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            ans+=cust[i];
        }
       int st=0,end=0;
       int s=0,c=0;
       int res=0;
       while(end<n)
       {
          if(grumpy[end]==1)
          s+=cust[end];
          if(end-st+1==mins)
          {
              int temp=ans+s;
              res=max(res,temp);
              if(grumpy[st]==1)
              s-=cust[st];
              st++;
          }
          end++;
       }
       return res;
    }
};