using ll=long long;
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        vector<ll> pref(27,0);
        int avl=0;
        int oddavl=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
                pref[words[i][j]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            avl+=(pref[i]/2);
            oddavl+=pref[i]%2;
        }
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
            pq.push(words[i].size());
        while(pq.size())
        {
            int len=pq.top();
            pq.pop();
            int p1=len/2;
                if(avl>=p1)
                {
                    avl-=p1;
                    ans++;
                }
        }
        return ans;
    }
};