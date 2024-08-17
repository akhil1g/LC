class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        int n=s.size();
        char ch;
        for(int i=0;i<n;i++){
            if(s[i]!=','){
                st.push(s[i]);
            }
            if(s[i]==')'){
                int t=0,f=0;
                while(st.size()&&st.top()!='('){
                    if(st.top()=='t'){
                        t++;
                    }
                    else
                    if(st.top()=='f'){
                        f++;
                    }
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                if(op=='&'){
                    if(f>0){
                        st.push('f');
                    }
                    else{
                        st.push('t');
                    }
                }
                else
                if(op=='|'){
                    if(t>0){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
                else
                if(op=='^'){
                    if(t==0){
                        st.push('f');
                    }
                    else
                    if(f==0){
                        if(t&1){
                            st.push('t');
                        }
                        else{
                            st.push('f');
                        }
                    }
                    else{
                        if(t&f){
                            st.push('t');
                        }
                        else{
                            st.push('f');
                        }
                    }
                }
                else
                if(op=='!'){
                    if(t>0){
                        st.push('f');
                    }
                    else{
                        st.push('t');
                    }
                }
                cout<<t<<" "<<f<<" "<<op<<" "<<st.top()<<"\n";
            }
        }
        if(st.top()=='t')
        return true;
        return false;
    }
};