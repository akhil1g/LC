class Solution {
public:
    vector<int> t={-1,0,1,0,-1};
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++)
        {
            int nr=row+t[k];
            int nc=col+t[k+1];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]=='O'&&!vis[nr][nc])
            {
                vis[nr][nc]=1;
                dfs(nr,nc,grid,vis);
            }
        }
        
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&&grid[i][0]=='O')
            {
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1]&&grid[i][m-1]=='O')
            {
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j]&&grid[0][j]=='O')
            {
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][j]&&grid[n-1][j]=='O')
            {
                dfs(n-1,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
            }
        }
    }
};