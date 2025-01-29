class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0; 

        int i = 0; 
        int New = nums[0]; 
        
        for (int j = 1; j < nums.size(); j++) 
        {
            if (nums[j] != New) 
            {
                i++;  
                nums[i] = nums[j]; 
                New = nums[j]; 
            }
        }
        
        return i + 1;
    }
};

// return unique(nums.begin(),nums.end()) - nums.begin();