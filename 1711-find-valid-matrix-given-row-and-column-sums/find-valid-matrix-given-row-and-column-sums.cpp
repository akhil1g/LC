class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n=row.size();
        int m=col.size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mini=min(row[i],col[j]);
                arr[i][j]=mini;
                row[i]-=mini;
                col[j]-=mini;
            }
        }
        return arr;
    }
};