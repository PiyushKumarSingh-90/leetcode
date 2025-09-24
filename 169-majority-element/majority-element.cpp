class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int majority ;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)  // Standard loop with index
        {
            if(count == 0) 
            {
                majority = nums[i];  // Choose a new candidate
            }

            if(nums[i] == majority) 
                count++;   // Increase count if it's the same as the majority
            else 
                count--;   // Decrease count if it's a different number
        }

        return majority;

    }
            
};