class Solution {
public:
    void solve(vector<int>& c, int target, int start, vector<int>& smallans, vector<vector<int>>& ans) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            ans.push_back(smallans);
            return;
        }
        
        for (int i = start; i < c.size(); i++) {
            smallans.push_back(c[i]);
            solve(c, target - c[i], i, smallans, ans);
            smallans.pop_back();
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> smallans;
        solve(candidates, target, 0, smallans, ans);
        return ans;
    }
};
