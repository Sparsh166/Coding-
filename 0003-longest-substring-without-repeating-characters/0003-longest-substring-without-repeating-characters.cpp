class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        map<char,int>mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                l = max(l,mp[s[r]]+1);
            }
            mp[s[r]] = r;
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};