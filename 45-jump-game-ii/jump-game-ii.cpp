class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int jumps =0;
        int current = 0;
        int maxReach = 0;


        if(n==1) return 0;

        

        for(int i = 0 ; i < n-1 ; i++)
        {
            maxReach = max(maxReach, i + nums[i]);

            if(i == current)
            {
                jumps++;
                current = maxReach;
            }

            if(current >= n-1) break;
        }

        return jumps;
    }
};