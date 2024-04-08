class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sand) {
        int n=st.size();
        int ones=0,z=0;
         for(int i=0;i<n;i++)
         {
            if(st[i]==1)
            ones++;
            else
            z++;
         }
        int c1=0,c2=0;
        for(int i=0;i<sand.size();i++)
        {
            if(sand[i]==1)
            c1++;
            else
            c2++;
            if(c1>ones||c2>z)
            {
                return (sand.size()-i);
            }
        }
        return 0;
    }
};