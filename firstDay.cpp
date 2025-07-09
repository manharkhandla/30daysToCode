#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(s<=e)
        {
            mid = (s+e)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target)
            {
                s = mid + 1;
            }
            else if(nums[mid]>target)
            {
                e = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    vector<int> v = {-1,0,3,5,9,12};
    cout<<s.search(v,9);
    return 0;
}