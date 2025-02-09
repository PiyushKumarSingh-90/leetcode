class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n == 0) return 0; // Edge case

        vector<int> leftMax(n), rightMax(n);
        int totalWater = 0;

        // Precompute leftMax
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) 
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Precompute rightMax
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) 
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate total trapped water
        for (int i = 0; i < n; i++) 
        {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};