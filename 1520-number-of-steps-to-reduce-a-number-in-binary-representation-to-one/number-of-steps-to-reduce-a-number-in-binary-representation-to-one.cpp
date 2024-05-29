class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int c=0;
        int ans=0;
        while(s.length()>=1)
        {
            if(s[s.length()-1]=='0')
            {
                if(c==0)
                {
                    ans++;
                    s.pop_back();
                }
                else
                {
                    s[s.length()-1]='1';
                    c=0;
                }
            }
            else
            {
                if(s.length()==1&&c==0)
                break;
                if(c==1)
                {
                    ans++;
                    s.pop_back();
                }
                else
                {
                    c=1;
                    ans+=2;
                    s.pop_back();
                }
            }
        }
        return ans;
    }
};