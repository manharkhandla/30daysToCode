class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n = nums.size();

        vector<string> ans;
        if (n == 0) return ans;
        if (n == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        int prev = nums[0];
        int j = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] != prev + 1) {

                if (j == i - 1) {
                    ans.push_back(to_string(nums[j]));
                } else {
                    ans.push_back(to_string(nums[j]) + "->" + to_string(prev));
                }

                j = i;
            }

            prev = nums[i];
        }

        // Handle the last range
        if (j == n - 1) {
            ans.push_back(to_string(nums[j]));
        } else {
            ans.push_back(to_string(nums[j]) + "->" + to_string(prev));
        }

        return ans;
    }
};