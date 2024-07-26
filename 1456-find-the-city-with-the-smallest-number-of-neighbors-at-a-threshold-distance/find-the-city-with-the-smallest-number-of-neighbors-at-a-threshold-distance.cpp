class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++)
        {
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        dist[i][i]=0;
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
            }
        }
        int node=0;
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&dist[i][j]<=thres)
                temp++;
            }
            if(ans>temp)
            {
                ans=temp;
                node=i;
            }
            else
            if(ans==temp)
            node=max(node,i);
        }
        return node;
    }
};