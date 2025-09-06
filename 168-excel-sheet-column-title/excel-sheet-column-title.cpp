class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            columnNumber--;
            int remainder = columnNumber % 26;
            ans = char('A' + remainder) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};