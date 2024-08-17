class Solution {
public:
    int fun(vector<int> &heights){
        
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<n;i++)
        cout<<heights[i]<<" ";
        cout<<"\n";
        vector<int> nextsmaller(n,-1);
        for(int i=n-1;i>=0;i--){
            while(st.size()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.size()){
                nextsmaller[i]=st.top();
            }
            st.push(i);            
        }
        vector<int> prevsmaller(n,-1);
        stack<int> st2;
        for(int i=0;i<n;i++){
            while(st2.size()&&heights[i]<=heights[st2.top()]){
                st2.pop();
            }
            if(st2.size()){
                prevsmaller[i]=st2.top();
            }
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        cout<<prevsmaller[i]<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++)
        cout<<nextsmaller[i]<<" ";
        cout<<"\n";
        for(int i=0;i<n;i++){
            int h=heights[i];
            int temp=0;
            if(h!=0){
                if(prevsmaller[i]==-1&&nextsmaller[i]==-1){
                    temp=h*n;
                    ans=max(ans,h*n);
                }
                else
                if(prevsmaller[i]!=-1&&nextsmaller[i]!=-1){
                    temp=h*(nextsmaller[i]-prevsmaller[i]-1);
                    ans=max(ans,h*(nextsmaller[i]-prevsmaller[i]-1));
                }
                else
                if(prevsmaller[i]==-1){
                    temp=h*(nextsmaller[i]+1);
                    ans=max(ans,h*(nextsmaller[i]));
                }
                else
                if(nextsmaller[i]==-1){
                    temp=h*(n-prevsmaller[i]-1);
                    ans=max(ans,h*(n-prevsmaller[i]-1));
                }
            }
            cout<<temp<<" ";
        }
        cout<<"\n";
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            vector<int> heights(m,0);
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=h[j]+1;
                }
            }
            h=heights;
            int temp=fun(heights);
            cout<<temp<<"\n";
            ans=max(ans,temp);
        }
        return ans;
    }
};