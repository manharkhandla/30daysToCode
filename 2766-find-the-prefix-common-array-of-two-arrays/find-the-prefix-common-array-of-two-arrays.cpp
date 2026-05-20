class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> ans(n,0);
        int count = 0;

        if(A[0]==B[0])
        {
            ans[0] = 1;
            count++;
        }
        ans[n-1] = n;

        vector<int> freq(n+1,0);

        freq[A[0]]++;
        freq[B[0]]++;
        

        for(int i=1;i<n-1;i++)
        {
            
            freq[A[i]]++;
            freq[B[i]]++;

            
            if(freq[A[i]]==2) count++;
            if(freq[B[i]]==2) count++;
            if(A[i]==B[i]) count--;
            
            ans[i] = count;
        }

        return ans;

    }
};