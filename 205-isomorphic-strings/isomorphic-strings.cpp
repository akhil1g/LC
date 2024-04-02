class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        map<char,char> mp,v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
            {
                if(mp.find(s[i])==mp.end())
                {
                    if(v[t[i]-'a']==0)
                    {
                        v[t[i]-'a']=1;
                        mp[s[i]]=t[i];
                    }
                    else
                    return false;
                }
                else
                if(mp[s[i]]!=t[i])
                return false;
            }
            else
            {
                if(mp.find(s[i])==mp.end())
                {
                    if(v[t[i]-'a']==0)
                    {
                        v[t[i]-'a']=1;
                        mp[s[i]]=t[i];
                    }
                    else
                    return false;
                }
                else
                if(mp[s[i]]!=t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};