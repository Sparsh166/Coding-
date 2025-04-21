class Solution {
public:
    string frequencySort(string s) {
        typedef pair<char,int> P;
        vector<P> vec(123);
        for(char&ch:s){
            int freq = vec[ch].second;
            vec[ch] = {ch,freq+1};
        }
        auto lambda = [&](P&p1, P&p2){
            return p1.second>p2.second;
        };
        sort(begin(vec),end(vec),lambda);
        string result = "";
        for(int i=0;i<123;i++){
            if(vec[i].second>0){
                int freq = vec[i].second;
                char ch = vec[i].first;
                string temp = string(freq,ch);
                result+=temp;
            }
        }
        return result;
    }
};