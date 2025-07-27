class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];
        if(n==2)
        {
            if(arr[0]==arr[1]) return arr[0];
        }
        int ans = arr[0];

        int count = 0;

        for(int i=0;i<n-1;i++)
        {
            int j = i+1;
            while(j<n && arr[i]==arr[j])
            {
                j++;
            }

            count = j-i;
            if(count>=n/4) ans = arr[i];
            i = j;
        }

        return ans;
    }
};