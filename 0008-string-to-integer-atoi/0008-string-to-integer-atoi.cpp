class Solution {
    int convert(const std::string& str, int num, int i, int sign) {
        if (i == str.length()) {
            return num * sign;
        }

        if (!isdigit(str[i])) {
            return num * sign;
        }

        int digit = str[i] - '0';

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        int newNum = num * 10 + digit;
        return convert(str, newNum, i + 1, sign);
    }

public:
    int myAtoi(const std::string& str) {
        int num = 0;
        int sign = 1;
        int i = 0;

        if (str.empty()) {
            return 0;
        }

        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '-' || str[i] == '+') {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        return convert(str, num, i, sign);
    }
};
