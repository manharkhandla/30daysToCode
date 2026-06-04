class Solution {
public:

    int findWaviness(int num)
    {
        string number = to_string(num);
        int wavi = 0;
        int l = number.length();

        if(l<3) return 0;

        for(int i=1;i<=l-2;i++)
        {
            if(number[i] > number[i-1] && number[i] > number[i+1]) wavi++;
            if(number[i] < number[i-1] && number[i] < number[i+1]) wavi++;
        }

        return wavi;
    }

    int totalWaviness(int num1, int num2) {
        
        int ans = 0;

        for(int i=num1;i<=num2;i++)
        {
            ans += findWaviness(i);
        }

        return ans;

    }
};