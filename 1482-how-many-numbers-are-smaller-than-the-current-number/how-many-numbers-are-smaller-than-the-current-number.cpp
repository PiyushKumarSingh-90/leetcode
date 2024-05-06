class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int>output(nums.size());


        for(int i=0;i<nums.size();i++)
        {
            int small=0;

            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]>nums[j] && nums[i]!=nums[j])
                {
                    small++;
                }
                output[i]=small;
            }
        }

        return output;
    }
};