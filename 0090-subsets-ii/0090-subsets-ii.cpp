class Solution {
private:
    void helper(vector<int> &nums, set<vector<int>> &ans, vector<int> smallans, int i){
        
        if(i>=nums.size()){
            ans.insert(smallans);
            return;
        }
        
        //don't take
        helper(nums, ans, smallans, i+1);
        
        //take element
        smallans.push_back(nums[i]);
        helper(nums, ans, smallans, i+1);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> smallans;
        sort(nums.begin(), nums.end());
        helper(nums, ans, smallans, 0);
        vector<vector<int>> res (ans.begin(), ans.end());
        return res;
        
    }
};