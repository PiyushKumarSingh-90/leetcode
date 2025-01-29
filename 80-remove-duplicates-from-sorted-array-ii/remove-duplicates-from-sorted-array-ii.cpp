class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() <= 2) return nums.size(); // Already valid

        int j = 2; // Position for next valid element
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[j - 2]) { // Allow max 2 occurrences
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};