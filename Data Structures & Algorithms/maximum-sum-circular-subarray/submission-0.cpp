class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curr_max = 0;
        int curr_min = 0;
        int totalMax = INT_MIN;
        int totalMin = INT_MAX;

        for(auto x : nums){
            curr_max = max(curr_max+x , x);
            totalMax = max(curr_max,totalMax);

            curr_min = min(curr_min+x,x);
            totalMin = min(totalMin,curr_min);

            total += x;
        }
        return totalMax < 0 ? totalMax : max(totalMax,total-totalMin);
    }
};