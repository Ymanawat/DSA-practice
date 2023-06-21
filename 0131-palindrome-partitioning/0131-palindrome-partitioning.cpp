class Solution {
private:
    void solve(string& s, int start, vector<string>& smallans, vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(smallans);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                string substring = s.substr(start, end - start + 1);
                smallans.push_back(substring);
                solve(s, end + 1, smallans, ans);
                smallans.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> smallans;
        solve(s, 0, smallans, ans);
        return ans;
    }
};
