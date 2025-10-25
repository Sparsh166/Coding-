class Solution {
public:
    int totalMoney(int n) {
      int ans = 0;
      int k = 1;
      while(n!=0){
        int a = k;
        for(int i =0;i<7;i++){
            if(n==0) break;
            ans += a;
            n--;
            a++;
        }
        k++;
      }
      return ans;
    }
};