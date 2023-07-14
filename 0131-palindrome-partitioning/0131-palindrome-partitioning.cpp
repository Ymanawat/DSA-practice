class Solution {
public:
    bool isPalindrome(string str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }

    void solve(string s, int idx, vector<vector<string>>& ans, vector<string>& smallans) {
        if (idx == s.size()) {
            ans.push_back(smallans);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (isPalindrome(s, idx, i)) {
                smallans.push_back(sub);
                solve(s, i + 1, ans, smallans);
                smallans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> smallans;
        solve(s, 0, ans, smallans);
        return ans;
    }
};
