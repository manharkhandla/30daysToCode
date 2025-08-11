class Solution {
public:

    void heapify(vector<int>& nums,int i,int n)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i +2;

        if(left<n && nums[left]>nums[largest]) largest = left;
        if(right<n && nums[right]>nums[largest]) largest = right;
        if(largest != i)
        {
            swap(nums[i],nums[largest]);
            heapify(nums,largest,n);
        }

        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i=(n/2)-1;i>=0;i--)
        {
            heapify(nums,i,n);
        }

        for(int i=n-1;i>=0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }

        return nums;

    }
};