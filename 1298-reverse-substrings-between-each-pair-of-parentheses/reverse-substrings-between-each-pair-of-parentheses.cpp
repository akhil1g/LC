class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<char> st;
        int i=0;
        while(i!=s.length())
        {
            if(s[i]==')')
            {
                string s1="";
                while(st.top()!='(')
                {
                    s1+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<s1.length();j++)
                st.push(s1[j]);
            }
            else
            st.push(s[i]);
            i++;
        }
        while(st.size())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};