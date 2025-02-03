class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) 
        {
            if(i > maxReach) return false;  // If we can't reach this index, return false
            
            maxReach = max(maxReach, i + nums[i]); // Update maxReach

            if(maxReach >= nums.size() - 1) return true; // If we reach or pass the last index,     return true
        }

        return true;  // If we exit the loop, return true
    }
};