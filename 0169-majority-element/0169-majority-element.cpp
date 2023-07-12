class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        map<int, int> countMap;

        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > nums.size() / 2) {
                return num;
            }
        }
        
        return 0;
    }
};
