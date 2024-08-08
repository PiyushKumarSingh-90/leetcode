class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n = 0;
        int count;
        for (int i = 0; i < nums.size(); i++)
        {
            count=0;

            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && nums[i] == nums[j])
                {
                    count++;
                    break;
                }
            }
            
            if (count==0)
            {
                n = nums[i];
                break;
            }
        }
        
        return n; 
    }
};