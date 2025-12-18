class Solution {
public:
    void helper(int n, int open, int close, string curr, vector<string>&ans){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            helper(n,open+1,close,curr,ans);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            helper(n,open,close+1,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string curr = "";
        vector<string>ans;
        helper(n,open,close,curr,ans);
        return ans;
    }
};