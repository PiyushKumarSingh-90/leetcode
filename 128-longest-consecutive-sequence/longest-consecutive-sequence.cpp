class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, bool> mp;
        
        int n = nums.size();
        int ans = 0;

        // Store elements in map and mark them as unvisited
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]] = false; // False means not visited
        }

        for(int i = 0; i < n; i++)
        {
            // Only start counting if the current element is not already visited
            if(mp[nums[i]] == false && mp.find(nums[i] - 1) == mp.end())
            {
                int length = 1;
                int num = nums[i];
                mp[num] = true;  // Mark as visited

                while(mp.find(num + 1) != mp.end() && mp[num + 1] == false)
                {
                    num++;
                    length++;
                    mp[num] = true;  // Mark as visited
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};