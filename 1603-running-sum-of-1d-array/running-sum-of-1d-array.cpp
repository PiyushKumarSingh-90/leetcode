class Solution 
{
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        

        vector<int>result(nums.size());

        int runningSum=0;

        for(int i=0;i<nums.size();i++)

        {
            runningSum+=nums[i];
            result[i]=runningSum;
        }

        return result;
    }
};