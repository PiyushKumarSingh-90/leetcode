class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        int count = 0;
        int ans = 0;
        int max = 0, secmax = 0, thrmax = 0;

        set<int> uniqueNums(nums.begin(), nums.end());
    

        vector<int> uniqueNumsArr;
        int n = uniqueNums.size();

        auto it = uniqueNums.begin();

        for (int i = 0; i < n; i++) 
        {
            uniqueNumsArr.push_back(*it);
            it++;
        }

        count=uniqueNumsArr.size();

        sort(uniqueNumsArr.begin(), uniqueNumsArr.end(), greater<int>());

        ans = uniqueNumsArr[2];

        if (count < 3) 
        {
            for (int i = 0; i < nums.size(); i++) 
            {
                if (max < nums[i]) 
                {
                    max = nums[i];
                }
            }
            return max;
        }

        return ans;
    }
};