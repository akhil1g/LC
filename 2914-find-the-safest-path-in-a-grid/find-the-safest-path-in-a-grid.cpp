class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int> t={0,1,0,-1,0};
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r=row+t[k];
                int c=col+t[k+1];
                if(r>=0&&c>=0&&r<n&&c<n){
                    if(dist[r][c]>1+dist[row][col]){
                        dist[r][c]=1+dist[row][col];
                        q.push({r,c});
                    }
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dist[0][0],{0,0}});
        while(pq.size()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1&&col==n-1)
            return d;
            for(int k=0;k<4;k++){
                int r=row+t[k];
                int c=col+t[k+1];
                if(r>=0&&c>=0&&r<n&&c<n&&!vis[r][c]){
                    vis[r][c]=1;
                    pq.push({min(dist[r][c],d),{r,c}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dist[n-1][n-1];
    }
};