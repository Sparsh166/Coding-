class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i =0;
        int j =0;
        int n = nums1.size()+nums2.size();
        int ind1 = (n/2)-1;
        int ind2 = (n/2);
        int elind1 = -1;
        int count = 0;
        int elind2 = -1;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(count==ind1){elind1 = nums1[i];}
                if(count==ind2){elind2 = nums1[i];}
                count++;
                i++;
            }
            else{
                if(count==ind1){elind1 = nums2[j];}
                if(count==ind2){elind2 = nums2[j];}
                count++;
                j++;
            }
        }
        while(i<nums1.size()){
            if(count==ind1){elind1 = nums1[i];}
            if(count==ind2){elind2 = nums1[i];}
            count++;
            i++;
        }
        while(j<nums2.size()){
            if(count==ind1){elind1 = nums2[j];}
            if(count==ind2){elind2 = nums2[j];}
            count++;
            j++;
        }
        if(n%2==1){return elind2;}
        else{
            return (double)((double)(elind1+elind2))/2.0;
        }
    }
};