class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int n = s.length();
        int maxlen = 0;
        map<char,int>mp;
        for(int r=0;r<n;r++){
            if(mp.find(s[r])!=mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]]=r;
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};