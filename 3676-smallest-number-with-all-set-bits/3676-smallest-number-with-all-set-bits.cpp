class Solution {
public:
    int smallestNumber(int n) {
        int tempans = n|n>>1;
        int ans =0;
        while(n!=0){
            n = n>>1;
            ans = ans<<1;
            ans = ans|1;
        }
        return ans;
    }
};