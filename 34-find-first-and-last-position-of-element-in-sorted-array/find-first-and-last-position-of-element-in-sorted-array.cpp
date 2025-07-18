class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        if(n == 0) return ans;

        int l = 0, h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        if(l >= n || nums[l] != target) return ans;
        ans[0] = l;

        h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        ans[1] = h;
        return ans;
    }
};
