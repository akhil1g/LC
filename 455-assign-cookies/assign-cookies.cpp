class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int k=0;
        int n=s.size();
        int m=g.size();
        for(int i=0;i<n;i++){
            if(k<m){
                if(s[i]>=g[k]){
                    k++;
                    ans++;
                }
            }
        }
        return ans;
    }
};