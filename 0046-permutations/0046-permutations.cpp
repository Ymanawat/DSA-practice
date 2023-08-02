class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // To store the permutations
        vector<int> current; // To store the current permutation being generated
        vector<bool> visited(nums.size(), 0);

        // Recursive backtracking function to generate permutations
        // 'start' represents the current index in nums we are considering for the permutation
        // 'visited' is a boolean array to keep track of which elements have already been used in the permutation
        // When the current permutation reaches the size of nums, it is added to the 'result' vector
        // Then we backtrack and try other elements at the current index.
        // This ensures all permutations are generated.
        function<void(int)> backtrack = [&](int start) {
            if (start == nums.size()) {
                result.push_back(current); // Add the current permutation to the result
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                if (!visited[i]) { // If the element at index 'i' is not used in the current permutation
                    visited[i] = true; // Mark the element as visited
                    current.push_back(nums[i]); // Add the element to the current permutation
                    backtrack(start + 1); // Generate permutations for the next index
                    current.pop_back(); // Remove the last added element (backtrack)
                    visited[i] = false; // Mark the element as not visited (backtrack)
                }
            }
        };

        backtrack(0); // Start generating permutations from index 0
        return result;
    }
};
