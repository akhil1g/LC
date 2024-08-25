class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s=-1e9,s1=1e9;
        int c=0,c1=0;
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
            c+=nums[i];
            c1+=nums[i];
            s=max(s,c);
            s1=min(s1,c1);
            if(c1>0){
                c1=0;
            }
            if(c<0){
                c=0;
            }
        }
        if(s1==tot){
            return s;
        }
        // cout<<s<<" "<<s1<<" "<<tot<<"\n";
        
        return max(s,tot-s1);
    }
};