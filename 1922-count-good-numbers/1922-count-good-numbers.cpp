class Solution {
public:
    const int M = 1e9 + 7;
    long long power(long long a, long long b){
        if(b==0)return 1;
        long long half = power(a,b/2);
        long long ans = (half*half)%M;
        if(b%2==1){
            ans = (ans*a)%M;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = (n/2);
        long long result = (power(5,even)*power(4,odd))%M;
        return result;
    }
};