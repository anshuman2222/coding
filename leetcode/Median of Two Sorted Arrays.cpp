class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        int i = 0, j = 0;
        
        while(i < l1 && j < l2) {
            if(nums1[i] < nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < l1) {
            v.push_back(nums1[i]);
            i++;
        }
        while(j < l2) {
            v.push_back(nums2[j]);
            j++;
        }
        int size = l1 + l2;
        
        if (size & 1) {
            return v[size/2];
        } else {
            return (v[(size/2)-1] + v[size / 2])/2.0;
        }
    }
};
