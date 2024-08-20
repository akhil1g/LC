class Solution {
public:
    int calculate(string s) {
        stack<char> st2;
        stack<string> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                string temp="";
                while(i<n&&isdigit(s[i])){
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
                i--;
            }
            else{
                if(s[i]=='('){
                    st2.push(s[i]);
                }
                else
                if(s[i]==')'){
                    while(st2.size()&&st2.top()!='('){
                        string t="";
                        t+=st2.top();
                        st.push(t);
                        st2.pop();
                    }
                    st2.pop();
                }
                else
                if(s[i]=='+'||s[i]=='-'){
                    while(st2.size()&&(st2.top()=='*'||st2.top()=='/'||st2.top()=='+'||st2.top()=='-'||st2.top()=='^')){
                        string t="";
                        t+=st2.top();
                        st.push(t);
                        st2.pop();
                    }
                    st2.push(s[i]);
                }
                else
                if(s[i]=='*'||s[i]=='/'){
                    while(st2.size()&&(st2.top()=='*'||st2.top()=='/'||st2.top()=='^')){
                        string t="";
                        t+=st2.top();
                        st.push(t);
                        st2.pop();
                    }
                    st2.push(s[i]);
                }
                else
                if(s[i]=='^'){
                    while(st2.size()&&st2.top()=='^'){
                        string t="";
                        t+=st2.top();
                        st.push(t);
                        st2.pop();
                    }
                    st2.push(s[i]);
                }
                else
                if(s[i]==' ')
                continue;
            }
        }
        while(st2.size()){
            string t="";
            t+=st2.top();
            st.push(t);
            st2.pop();
        }
        vector<string> temp;
        int ans=0;
        while(st.size()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<"\n";
        stack<int> eval;
        for(int i=0;i<temp.size();i++){
            if(eval.size()==0){
                eval.push(stoi(temp[i]));
            }
            else{
                if(temp[i][0]!='+'&&temp[i][0]!='-'&&temp[i][0]!='*'&&temp[i][0]!='/'){
                    eval.push(stoi(temp[i]));
                }
                else{
                    int a=0,b=0;
                    if(eval.size()){
                        a=eval.top();
                        eval.pop();
                    }
                    if(eval.size()){
                        b=eval.top();
                        eval.pop();
                    }
                    char op=temp[i][0];
                    if(op=='+'){
                        eval.push(a+b);
                    }
                    else
                    if(op=='-'){
                        eval.push(b-a);
                    }
                    else
                    if(op=='*'){
                        eval.push(a*b);
                    }
                    else
                    if(op=='/'){
                        eval.push(b/a);
                    }
                }
            }
        }
        ans=eval.top();
        return ans;   
    }
};