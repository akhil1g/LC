class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        int n=score.size();
        vector<string> ans(n);
        int i=0;
        while(pq.size())
        {
            int tp=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(i==0)
            {
                ans[index]="Gold Medal";
            }
            else
            if(i==1)
            {
                ans[index]="Silver Medal";
            }
            else
            if(i==2)
            {
                ans[index]="Bronze Medal";
            }
            else
            {
                ans[index]=to_string(i+1);
            }
            i++;
        }
        return ans;
    }
};