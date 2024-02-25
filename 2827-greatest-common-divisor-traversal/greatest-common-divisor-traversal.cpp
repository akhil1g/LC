class Solution {
public:
    unordered_set<int> UniquePrimeFactors(int n){
        unordered_set<int> factors;
        for(int i=2; i<= sqrt(n); i++){
            while(n%i == 0){
                factors.insert(i);
                n /= i;
            }
        }
        if(n > 1) factors.insert(n);
        return factors;
    }
    void dfs(int i, set<int>& vis, vector<vector<int>>& adj){
        vis.insert(i);
        for(int node: adj[i]){
            if(vis.find(node) == vis.end()) 
            dfs(node, vis, adj);
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        unordered_map<int, int> lastIndex;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> primeFactors = UniquePrimeFactors(nums[i]);
            for(int factor: primeFactors){
                if(lastIndex.find(factor) != lastIndex.end()){
                    int prevIndex = lastIndex[factor];
                    adj[prevIndex].push_back(i);
                    adj[i].push_back(prevIndex);
                }
                lastIndex[factor] = i;
            }
        }
        set<int> vis;
        dfs(0, vis, adj);
        return vis.size() == n;
    }
};