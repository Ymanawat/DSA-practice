class Solution {
public:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string& digits, int index, vector<string>& ans, string& smallans) {
        if (index == digits.length()) {
            ans.push_back(smallans);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = map[digit];
        
        for (char letter : letters) {
            smallans.push_back(letter);
            solve(digits, index + 1, ans, smallans);
            smallans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if (digits.empty()) {
            return ans;
        }
        
        string smallans;
        solve(digits, 0, ans, smallans);
        
        return ans;
    }
};
