class Solution {
public:
    int lowerbound(vector<int>&arr, int x){
        int low = 0;
        int n = arr.size();
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){return mid;}
            else if(arr[mid]>x){high=mid-1;}
            else{low=mid+1;}
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int sol = lowerbound(matrix[i],target);
            if(sol!=-1){return true;}
        }
        return false;
    }
};