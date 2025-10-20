class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      int n = operations.size();
      int num = 0;
      for(int i = 0; i<n;i++){
        if (operations[i]=="--X" || operations[i]=="X--"){
            num = num-1;
        }
        else{
            num = num+1;
        }
      }  
      return num;
    }
};