class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0; // Handle edge case

        int i = 0; // Pointer for unique elements
        int New = nums[0]; // Track last unique element
        
        for (int j = 1; j < nums.size(); j++) 
        {
            if (nums[j] != New) 
            {
                i++;  
                nums[i] = nums[j]; // Place unique element in the array
                New = nums[j]; // Update last unique element
            }
        }
        
        return i + 1;
    }
};

// return unique(nums.begin(),nums.end()) - nums.begin();