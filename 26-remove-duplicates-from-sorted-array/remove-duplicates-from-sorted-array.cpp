class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        
       if (nums.empty()) return 0; 

        int i = 0;  
        int j = 1;  

        while (j < nums.size()) 
        {
            if (nums[j] != nums[i]) 
            {
                i++;  
                nums[i] = nums[j]; // Move unique element forward
            }
            j++; // Move scanning pointer
        }
        
        return i + 1; 
    }
};

// return unique(nums.begin(),nums.end()) - nums.begin();