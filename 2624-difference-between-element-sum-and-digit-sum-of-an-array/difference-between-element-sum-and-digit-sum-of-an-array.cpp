class Solution 
{
public:
    int differenceOfSum(vector<int>& nums) 
    {
        
        int elementsum = 0;
        int digitsum = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            elementsum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            while (nums[i] != 0) 
            {
                digitsum = digitsum + nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
        }
        return elementsum - digitsum;
    }
};