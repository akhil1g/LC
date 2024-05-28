class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n=s.length();
        int ans=0;
        int st=0,e=0;
        int k=0;
        while(e<n)
        {
            k+=abs(t[e]-s[e]);
            while(k>cost)
            {
                k-=abs(t[st]-s[st]);
                st++;
            }
            ans=max(ans,e-st+1);
            e++;
        }
        return ans;
    }
};