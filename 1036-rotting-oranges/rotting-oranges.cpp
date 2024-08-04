class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
                else
                if(grid[i][j]==1)
                c++;
            }
        }
        if(c==0)
        return 0;
        vector<int> t={1,0,-1,0,1};
        int ans=0;
        while(q.size()){
            int time=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            ans=time;
            // cout<<row<<" "<<col<<" "<<c<<" "<<time<<"\n";
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=row+t[k];
                int nc=col+t[k+1];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==1)
                {
                    c--;
                    grid[nr][nc]=2;
                    q.push({time+1,{nr,nc}});
                }
            }
        }
        if(c!=0)
        return -1;
        return ans;
    }
};