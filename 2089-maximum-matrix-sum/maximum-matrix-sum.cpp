class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        long long absoluteSum = 0;
        int numberOfNegative = 0;
        int minimumEl = INT_MAX;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                absoluteSum += abs(matrix[i][j]);
                if(matrix[i][j]<0) numberOfNegative++;
                if(abs(matrix[i][j]) < minimumEl) minimumEl = abs(matrix[i][j]);
            }
        }

        if(numberOfNegative%2==0) return absoluteSum;

        return (absoluteSum - 2*minimumEl);

    }
};