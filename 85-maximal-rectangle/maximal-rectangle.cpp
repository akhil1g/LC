class Solution {
public:
    int fun(vector<int> &h)
    {
        
        stack<int> st1;
        int n=h.size();
        vector<int> prev(n,-1),next(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(st1.size()&&h[st1.top()]>h[i])
            {
                prev[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
        stack<int> st2;
        for(int i=0;i<n;i++)
        {
            while(st2.size()&&h[st2.top()]>h[i])
            {
                next[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,abs(next[i]-prev[i]-1)*h[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                h[j]=0;
                else
                h[j]++;
            }
            ans=max(ans,fun(h));
        }   
        return ans;
    }
};