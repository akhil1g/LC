class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;;
        int l=log2(n);
        return n-(1<<l)==0?1:0;
    }
};