class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        queue<int> posIdx;
        queue<int> negIdx;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) posIdx.push(i);
            if(nums[i]<0) negIdx.push(i);
        }

        for(int i=0;i<n/2;i++)
        {
            ans.push_back(nums[posIdx.front()]);
            ans.push_back(nums[negIdx.front()]);
            posIdx.pop();
            negIdx.pop();
        }

        return ans;
    }
};