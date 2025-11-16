class Solution {
public:
    string largestOddNumber(string num) {
     int n = num.size();
     string ans ="";
     if(num[n-1]%2==1){return num;}
     else{
        for(int i=n-1;i>=0;i--){
            if(num[i]%2==1){
                ans=num.substr(0,i+1);
                break;
            }
        }
     }
     return ans;
    }
};