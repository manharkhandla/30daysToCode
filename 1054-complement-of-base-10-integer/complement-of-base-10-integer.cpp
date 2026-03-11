class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int count = 0;
        int ans = 0;

        while(n>0)
        {
            int remainder = n%2;
            ans += (!remainder)*(pow(2,count));
            n/=2;
            count++;
        }

        return ans;

    }
};