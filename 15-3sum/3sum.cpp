class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) { 
            // Skip duplicate numbers to avoid repeating triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1; // Two-pointer approach
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; 

                if (sum == 0) { 
                    result.push_back({nums[i], nums[left], nums[right]}); // Found a valid triplet
                    left++; right--; // Move both pointers

                    // Skip duplicate numbers
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if (sum < 0) left++;  // Increase sum by moving `left` right
                else right--;  // Decrease sum by moving `right` left
            }
        }
        return result;
    }
    
};