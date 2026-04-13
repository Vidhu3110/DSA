class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        int n = 2 ;
        int i = 0;
        while(n){
            ans.push_back(nums[i++]);
            if(i > nums.size()-1){
                n--;
                i = 0;
            }
        }
        return ans;
    }
};