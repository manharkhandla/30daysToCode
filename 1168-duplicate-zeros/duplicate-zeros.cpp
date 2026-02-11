class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> temp(n,0);
        for(int i=0;i<n;i++) temp[i]=arr[i];

        int p = 0;

        for(int j=0;j<n;j++)
        {
            if(temp[p]==0)
            {
                arr[j] = 0;

                if(j+1 < n)   
                {
                    arr[j+1] = 0;
                    j++;
                }
            }
            else arr[j]=temp[p];
            p++;
        }
        return;
    }
};