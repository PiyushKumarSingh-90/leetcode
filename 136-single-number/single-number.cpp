class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            bool found = false;

            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && nums[i] == nums[j])
                {
                    found = true;
                    break;
                }
            }
            
            if (!found)
            {
                n = nums[i];
                break;
            }
        }
        
        return n; 
    }
};