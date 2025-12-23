class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
            mp[ch]--;
            if(mp[ch]<0) return false;
        }
        return true;
    }
};