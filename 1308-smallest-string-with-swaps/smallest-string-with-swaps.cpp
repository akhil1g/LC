class Solution {
public:
    string orig;
    void dfs(int node,vector<int> adj[],multiset<char> &temp,vector<int> &vis,set<int> &path){
        if(vis[node]) return;
        vis[node]=1;
        path.insert(node);
        temp.insert(orig[node]);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,temp,vis,path);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans="";
        int n=s.size();
        orig=s;
        vector<int> adj[n];

        for(int i=0;i<pairs.size();i++){
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        queue<pair<set<int>,multiset<char>>> q;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                multiset<char> temp;
                set<int> path;
                dfs(i,adj,temp,vis,path);
                q.push({path,temp});
            }
        }
        while(q.size()){
            multiset<char> t=q.front().second;
            set<int> path=q.front().first;
            q.pop();
            auto it=path.begin();
            auto it1=t.begin();
            while(it!=path.end()){
                s[*it]=*it1;
                it++;
                it1++;
            }
        }
        return s;
    }
};