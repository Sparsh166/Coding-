class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int len = text.length();
        map<char,int> freq ; 
        for(int i=0;i<len;i++){
            freq[text[i]]++;
        }
        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l']/2;
        int o = freq['o']/2;
        int n = freq['n'];
        
        return min({b,a,l,o,n});
    }
};