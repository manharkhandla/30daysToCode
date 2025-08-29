class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int maxOne = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                maxOne = max(count,maxOne);
                count=0;
            }
            else count++;
        }
        maxOne = max(count,maxOne);
        return maxOne;
    }
};