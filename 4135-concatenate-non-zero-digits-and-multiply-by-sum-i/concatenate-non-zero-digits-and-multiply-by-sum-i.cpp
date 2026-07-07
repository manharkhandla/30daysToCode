class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long x = 0;
        int i = 0;

        while(n>0)
        {
            int last = n%10;
            if(last != 0)
            {
                x = x + (long long)(last * pow(10, i));
                i++;
            }
            n = n/10;
        }

        long long temp = x;
        long long sum = 0;

        while(temp>0)
        {
            int last = temp%10;
            sum = sum + last;
            temp /= 10;
        }

        return sum*x;

    }
};