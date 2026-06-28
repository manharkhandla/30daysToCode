class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();

        sort(arr.begin(),arr.end());

        int mx = -1;

        for(int i=0;i<n;i++)
        {
            if(i==0) arr[0] = 1;
            else if(abs(arr[i]- arr[i-1])) arr[i] = arr[i-1] + 1;

            mx = max(mx,arr[i]);
        } 


        return mx;

    }
};