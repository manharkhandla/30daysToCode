class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=0;
        int stream=1;

        while(i<target.size() && stream<=n)
        {
            ans.push_back("Push");

            if(target[i]==stream) i++;
            else ans.push_back("Pop");

            stream++;
        }

        return ans;
    }
};