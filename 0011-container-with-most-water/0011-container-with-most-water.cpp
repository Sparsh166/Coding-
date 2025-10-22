class Solution {
public:
    int maxArea(vector<int>& height) {
     int n = height.size();
     int ans = 0;
     int left = 0;
     int right = n-1;
     while(left<right){
        int width = right - left;
        int high = min(height[right],height[left]);
        int area = width*high;
        ans = max(area,ans);
        if (height[left]>height[right]){
            right--;
        }
        else{
            left++;
        }
     }
     return ans;
    }
};