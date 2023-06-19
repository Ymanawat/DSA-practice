class Solution {
private:
    void merge(vector<int> &nums, int l, int mid, int r) {
        vector<int> tempsorted;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tempsorted.push_back(nums[i++]);
            }
            else {
                tempsorted.push_back(nums[j++]);
            }
        }
        while (i <= mid) {
            tempsorted.push_back(nums[i++]);
        }
        while (j <= r) {
            tempsorted.push_back(nums[j++]);
        }
        
        i = 0;
        j = l;
        while (j <= r) {
            nums[j++] = tempsorted[i++];
        }
    }
    
    void mergesort(vector<int> &nums, int l, int r) {
        
        if (l >= r) {
            return;
        }
        
        int mid = l + (r - l) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);   
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
