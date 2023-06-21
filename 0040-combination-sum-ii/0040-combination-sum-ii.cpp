class Solution {
public:
    void solve(vector<int>& c, int target, int start, vector<int>& smallans, set<vector<int>>& ans) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            ans.insert(smallans);
            return;
        }
        
        for (int i = start; i < c.size(); i++) {
            if (i > start && c[i] == c[i-1]) {
                continue;
            }
            
            smallans.push_back(c[i]);
            solve(c, target - c[i], i + 1, smallans, ans);
            smallans.pop_back();
        }
    }
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> smallans;
        solve(candidates, target, 0, smallans, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
