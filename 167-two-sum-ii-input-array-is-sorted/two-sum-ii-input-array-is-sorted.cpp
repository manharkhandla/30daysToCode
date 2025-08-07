class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,-1);
        int start = 0;
        int end = numbers.size() - 1;

        while(start<end)
        {
            if(numbers[start]+numbers[end]==target)
            {
                ans[0] = start+1;
                ans[1] = end+1;
                return ans;
            }
            else if(numbers[start]+numbers[end]>target)
            {
                end-=1;
            }
            else start+=1;
        }
        
        return ans;
    }
};