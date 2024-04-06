class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_map<int,int> m;
        stack<pair<char,int>> st;
        string ans="";
        int prev=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                while(st.size()&&st.top().first!='(')
                {
                    st.pop();
                }
                if(st.size()&&st.top().first=='(')
                {
                    m[i]++;
                    m[st.top().second]++;  
                    st.pop();                  
                }
            }
            else
            st.push({s[i],i});
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]==')')
            {
                if(m.find(i)!=m.end())
                ans+=s[i];         
                else
                continue;       
            }
            else
            ans+=s[i];
        }
        return ans;
    }
};