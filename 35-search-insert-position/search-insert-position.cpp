class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid;

        if(target<nums[0]) return 0;
        while(s<=e)
        {
            mid = (s+e)/2;
            if(nums[mid]<target)
            {
                s=mid + 1;
            } 
            else if(nums[mid]>target)
            {
                e = mid - 1;
            } 
            else if(nums[mid]==target) return mid;
        }
        if(target<nums[mid]) return mid;
        return mid+1;
    }
};