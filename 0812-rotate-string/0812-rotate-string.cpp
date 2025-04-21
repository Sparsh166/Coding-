class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){return false;}
        string b = s+s;
        if(b.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};