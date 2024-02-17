class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int ans=0;
        int n=h.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int s=0;
        for(int i=1;i<n;i++)
        {
            if(h[i]>h[i-1])
            {
                if(pq.size()<l)
                    pq.push(h[i]-h[i-1]);
                else
                if(pq.size()==l&&l>0)
                {
                    if(pq.top()<h[i]-h[i-1])
                    {
                        s+=pq.top();
                        pq.pop();
                        pq.push(h[i]-h[i-1]);
                    }
                    else
                    s+=(h[i]-h[i-1]);
                }
                else
                s+=h[i]-h[i-1];
            }
            if(s<=b)
            {
                ans=i;
            }
            else
            break;
        }
        return ans;
    }
};