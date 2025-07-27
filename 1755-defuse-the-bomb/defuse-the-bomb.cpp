class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0); 
        int totalSum = 0;
        if(k>0)
        {
            for(int i=0;i<n;i++)
            {
                int sum = 0;
                for(int j=0;j<k;j++)
                {
                    int index = (i+j+1)%n;
                    sum += code[index];
                }
                ans[i] = sum;
            }
            return ans;
        }

        else if(k<0)
        {
            for(int i=0;i<n;i++)
            {
                int sum = 0;
                for(int j=0;j<(-k);j++)
                {
                    int index = (n-1-j+i)%n;
                    sum += code[index];
                }
                ans[i] = sum;
            }
            return ans;
        }

        return ans;
    }
};