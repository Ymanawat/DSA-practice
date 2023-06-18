class Solution {
private:
    //TC will be O(n*2^n) there are 2^n subsets and to process each will take n
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> smallans, int i){
        
        //base case
        if(i>=nums.size()){
            ans.push_back(smallans);
            return;
        }
        
        //don't take
        helper(nums, ans, smallans, i+1);
        
        //take element
        smallans.push_back(nums[i]);
        helper(nums, ans, smallans, i+1);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> smallans;
        
        helper(nums, ans, smallans, 0);
        return ans;
        
    }
};