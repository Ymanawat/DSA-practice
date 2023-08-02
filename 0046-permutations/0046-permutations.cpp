class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // To store the permutations

        // Recursive backtracking function to generate permutations
        // 'start' represents the current index in nums we are considering for the permutation
        // When the current permutation reaches the size of nums, it is added to the 'result' vector
        // Then we backtrack and try other elements at the current index.
        // This ensures all permutations are generated.
        function<void(int)> backtrack = [&](int start) {
            if (start == nums.size()) {
                result.push_back(nums); // Add the current permutation to the result
                return;
            }
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[start], nums[i]); // Swap elements to generate permutations
                backtrack(start + 1); // Generate permutations for the next index
                swap(nums[start], nums[i]); // Backtrack (undo the swap)
            }
        };

        backtrack(0); // Start generating permutations from index 0
        return result;
    }
};
