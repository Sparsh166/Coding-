class Solution {
public:
    int romanToInt(string s) {
        map<char,int>m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});
        int sum = m[s[s.size() -1]];
        for (int i=s.size()-2;i>=0;i--){
            if(m[s[i]]<m[s[i+1]]){
                sum-=m[s[i]];
            }
            else{
                sum+=m[s[i]];
            }
        }
        return sum;
    }
};