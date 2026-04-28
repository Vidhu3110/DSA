class Solution {
public:
vector<int> curr;
vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return res;
    }
    void backtrack(vector<int>& nums , int target , int sum,int i){
        int n = nums.size();
        if(sum == target){
            res.push_back(curr);
            return;
        }
        if(sum > target || i >= n)   return;
        curr.push_back(nums[i]);
        backtrack(nums,target,sum+nums[i],i);
        curr.pop_back();
        backtrack(nums,target,sum,i+1);
    }
};
