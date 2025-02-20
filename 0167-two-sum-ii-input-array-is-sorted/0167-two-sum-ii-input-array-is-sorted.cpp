class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      int sum = 0;
      int left = 0;
      int right =n-1;
      for(int i=0;i<n;i++){
        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum<target){
                left++;
            }
            else if (sum>target){
                right--;
            }
            else{
                return{left+1,right+1};
            }

        }
      }  
      return{};
    }
};