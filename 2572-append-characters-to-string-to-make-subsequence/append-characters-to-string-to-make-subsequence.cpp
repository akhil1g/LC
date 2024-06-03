class Solution {
public:
    bool issub(string &s1,string &s2,int n,int m)
    {
        if(m==s2.size()) return true;
        if(n==s1.size()&&m!=s2.size()) return false;
        if(s1[n]==s2[m]) return issub(s1,s2,n+1,m+1);
        return issub(s1,s2,n+1,m);
    }
    int appendCharacters(string s, string t) {
        // if(issub(s,t,0,0)) return 0;
        int ans=0,i=0,j=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==t[j])
            j++;
        }
        return t.size()-j;
    }
};