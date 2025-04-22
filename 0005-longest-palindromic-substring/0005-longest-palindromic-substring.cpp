class Solution {
public:
    string longestPalindrome(string s) {
       if(s.size()<=1){return s;}
       int max_len = 1;
       int start = 0;
       for(int i=0;i<s.size();i++){
        //for even
        int l = i;
        int r = i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            int len = r-l+1;
            if(len>max_len){
                max_len = len;
                start = l;
            }
            l--;r++;
        }
       }
       for(int i=0; i<s.size(); i++){
        //for odd
        int l = i-1;
        int r = i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            int len = r-l+1;
            if(len>max_len){
                max_len = len;
                start = l;
            }
            l--;r++;
        }
       }
       return s.substr(start,max_len); 
    }
};