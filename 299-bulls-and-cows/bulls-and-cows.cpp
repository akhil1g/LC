class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0;
        int n=secret.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                mp[secret[i]]++;
            }
        }
        int a=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                b++;
            }
            else
            if(mp.find(guess[i])!=mp.end()){
                mp[guess[i]]--;
                a++;
                if(mp[guess[i]]==0){
                    mp.erase(guess[i]);
                }
            }
        }
        string ans="";
        ans+=to_string(b)+'A'+to_string(a)+'B';
        return ans;
    }
};