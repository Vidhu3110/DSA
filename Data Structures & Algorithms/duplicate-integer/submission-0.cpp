class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]] = 0;
            }
            mp[nums[i]] += 1;
        }
        for(auto it : mp){
            if(it.second > 1){
                return true;
            }
        }
        return false;
    }
};