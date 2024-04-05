class Solution {
public:
    string makeGood(string s) {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(ans.size()==0)
            {
                ans+=s[i];
                continue;
            }
            if(isupper(s[i]))
            {
                char c=s[i];
                if(tolower(c)==ans.back())
                {
                    ans.pop_back();
                }
                else
                {
                    ans+=s[i];
                }
            }
            else
            {
                if(isupper(ans.back()))
                {
                    char c=ans.back();
                    if(tolower(c)==s[i])
                    {
                        ans.pop_back();
                    }
                    else
                    {
                        ans+=s[i];
                    }
                }
                else
                {
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};