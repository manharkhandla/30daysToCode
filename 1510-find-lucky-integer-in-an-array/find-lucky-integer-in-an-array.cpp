class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[0];

        for(int i=0;i<n;i++) if(arr[i]>mx) mx = arr[i];
        vector<int> freq(mx+1,0);

        for(int i=0;i<n;i++) freq[arr[i]]++;
        int ans = -1;
        for(int i=1;i<=mx;i++) if(freq[i]==i) ans = i;

        return ans;
    }
};