class Solution {
public:
    int helper(string s, int i, long long num, int sign){
        int min_value = INT_MIN;
        int max_value = INT_MAX;
        if(i>=s.size()||!isdigit(s[i])){
            return (int)(sign*num);
        }
        num = num*10+(s[i]-'0');
        if(sign*num>max_value){return INT_MAX;}
        if(sign*num<min_value){return INT_MIN;}
        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s, int i=0) {
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign = 1;
        if(i<s.size() && (s[i]=='+')|| (s[i]=='-')){
            sign = (s[i]=='-')?-1:1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};