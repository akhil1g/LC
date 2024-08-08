class Solution {
public:
    int minimumOneBitOperations(int n) {
        int i=1;
        
        string s="";
        int x=n;
        vector<int> ind;
        while(x){
            if(x&1){
                ind.push_back(i);
            }
            i++;
            x/=2;
        }
        int ans=0;
        if(ind.size()==1){
            return pow(2,ind[0])-1;
        }
        int k=0;
        for(int i=ind.size()-1;i>=0;i--){
            if(k&1){
                ans-=(pow(2,ind[i])-1);
            }
            else{
                ans+=(pow(2,ind[i])-1);
            }
            k++;
        }
        return ans;
    }
};