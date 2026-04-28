class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int>& nums , int i){
        int n = nums.size();
        if(i == n){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums,i+1);
        curr.pop_back();
        backtrack(nums,i+1);
    }
};
