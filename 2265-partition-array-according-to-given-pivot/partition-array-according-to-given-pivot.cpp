class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();

        vector<int> ans(n,pivot);

        int k = 0;
        int l = n-1;
        int j = n-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
            {
                ans[k] = nums[i];
                k++;
            }
            if(nums[j] > pivot)
            {
                ans[l] = nums[j];
                l--;
            }
            j--;
        }

        return ans;

    }
};