class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n);
        vector<pair<int,int>> temp(n);

        for(int i = 0; i < n; i++)
        {
            int noOfOne = 0;
            int x = arr[i];   

            while(x > 0) 
            {
                noOfOne += x % 2;
                x = x / 2;
            }

            
            temp[i] = {noOfOne, arr[i]};
        }

        sort(temp.begin(), temp.end());

        
        for(int i = 0; i < n; i++) ans[i] = temp[i].second;
            

        return ans;
    }
};