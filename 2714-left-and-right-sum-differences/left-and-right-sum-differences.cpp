class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> leftsum(n);
        vector<int> rightsum(n);
        
        int ptrLeft = 0;

        // Calculate leftSum
        for(int i = 0; i < n; i++)
        {
            leftsum[i] = ptrLeft;
            ptrLeft += nums[i];
        }

        // Calculate rightSum
        int ptrRight = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            rightsum[i] = ptrRight;
            ptrRight += nums[i];
        }

        // Calculate the answer array
        for(int i = 0; i < n; i++)
        {
            answer[i] = abs(leftsum[i] - rightsum[i]);
        }

        return answer;
    }

    
};