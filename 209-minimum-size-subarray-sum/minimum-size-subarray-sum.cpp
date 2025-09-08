class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        // int ans = n;
        // bool isChange = false;

        // for(int i=0;i<n;i++)
        // {
        //     int sum = 0;
        //     for(int j=i;j<n;j++)
        //     {
        //         sum+=nums[j];
        //         if(sum>=target)
        //         {
        //             ans=min(ans,j-i+1);
        //             isChange = true;
        //             break;
        //         }
        //     }
        // }

        // if(!isChange) return 0;
        // return ans;

        int sum = 0;

        int i=0,j=0;
        int ans = n;
        bool isChange = false;
        while(j<n)
        {
            sum+=nums[j];
            

            while(sum>=target)
            {
                sum-=nums[i];
                ans = min(ans,j-i+1);
                i++;
                isChange = true;
            }

            j++;
        }

        return isChange?ans:0;
    }
};