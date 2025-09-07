class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        long long rev = 0;
        while (n != 0)
        {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        return x==rev;

    }
};