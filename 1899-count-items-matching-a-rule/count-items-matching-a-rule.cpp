class Solution {
public:
        int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
     int cnt = 0;

        for(int i=0;i<items.size();i++){
            if(ruleKey =="type" && ruleValue == items[i][0]) cnt++;
            else if(ruleKey =="color" && ruleValue == items[i][1]) cnt++;
            else if(ruleKey =="name" && ruleValue == items[i][2]) cnt++;
        }
     return cnt;   
    }
};