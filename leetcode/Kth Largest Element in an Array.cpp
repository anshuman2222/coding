class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long len = nums.size();
        
        return nums[len - k];
    }
};
