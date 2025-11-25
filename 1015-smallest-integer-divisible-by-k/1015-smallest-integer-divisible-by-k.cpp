class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count = 1;
        if(k==1){
            return 1;
        }
        int rem = 1;
        if(k%2==0){
            return -1;
        }
        if(k%5==0){
            return -1;
        }
        while(count<=k){
            rem = (rem*10+1)%k;
            count++;
            if(rem==0){
                return count;
                break;
            }
        }
        return -1;
    }
};