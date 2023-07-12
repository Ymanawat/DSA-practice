class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int count = 0;
        int j = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } 
            else {
                count = 0;
            }

            if (count < 2) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
