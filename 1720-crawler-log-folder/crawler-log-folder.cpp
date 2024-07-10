class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        int n=logs.size();
        for(int i=0;i<n;i++)
        {
            if(logs[i]=="./")
            continue;
            else
            if(logs[i]=="../"&&ans>0)
            ans--;
            else
            if(logs[i][0]!='.')
            ans++;
        }
        return ans;
    }
};