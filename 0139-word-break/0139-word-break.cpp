class Solution {
public:
    unordered_set<string>st;
    vector<int> dp;
    bool helper(string&s,vector<string>& wordDict, int ind){
        if(ind==s.length()){
            return true;
        }
         if (dp[ind] != -1)
            return dp[ind];

        if(st.find(s)!=st.end()) return true;
        for(int l=1;l<=s.length();l++){
            string temp = s.substr(ind,l);
            if(st.find(temp)!=st.end() && helper(s,wordDict,ind+l)){
                return dp[ind] = 1;
            }
        }
        return dp[ind] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &word: wordDict){
            st.insert(word);
        }
        dp.assign(s.length(), -1);
        return helper(s,wordDict,0);
    }
};