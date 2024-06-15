class Solution {
public:
    class comparator
    {
        public:
        bool operator()(pair<int,int> &p1,pair<int,int> &p2)
        {
            if(p1.first==p2.first) return p1.second<p2.second;
            else
            return p1.first>p2.first;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(int i=0;i<profits.size();i++)
        {
            pq.push(make_pair(capital[i],profits[i]));
        }
        priority_queue<int> p;
        while(pq.size()&&k!=0)
        {
            while(pq.size()&&pq.top().first<=w)
            {
                p.push(pq.top().second);
                pq.pop();
                // k--;
            }
            k--;
            if(p.empty()) return w;
            w+=p.top();
            p.pop();
        }
            while(p.size()&&k!=0)
            {
                w+=p.top();
                p.pop();
                k--;
            }
        return w;
    }
};