class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int,int>> adj[n];
         for(int i=0;i<flights.size();i++)
             adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        vector<int> dist(n,1e9);
        dist[src]=0;
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push(make_pair(0,make_pair(src,0)));
        while(pq.size())
        {
            int node=pq.front().second.first;
            int d=pq.front().second.second;
            int steps=pq.front().first;
            pq.pop();
            if(steps>k) continue;
            for(auto it:adj[node])
            {
                if(d+it.second<dist[it.first]&&steps<=k)
                {
                    dist[it.first]=d+it.second;
                    pq.push(make_pair(steps+1,make_pair(it.first,d+it.second)));
                }
            }
        }
        return dist[dst]!=1e9?dist[dst]:-1;
    }
};