class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // queue<int> posIdx;
        // queue<int> negIdx;

        // for(int i=0;i<n;i++)
        // {
        //     nums[i]>0?posIdx.push(i):negIdx.push(i);
        // }

        // for(int i=0;i<n/2;i++)
        // {
        //     ans.push_back(nums[posIdx.front()]);
        //     ans.push_back(nums[negIdx.front()]);
        //     posIdx.pop();
        //     negIdx.pop();
        // }

        int pos = 0;
        int neg = 1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[pos] = nums[i];
                pos+=2;
            }
            else
            {
                ans[neg] = nums[i];
                neg+=2;
            }
        }

        return ans;
    }
};