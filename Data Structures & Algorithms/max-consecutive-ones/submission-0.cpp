class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0 , count = INT_MIN; 
        for(auto v : nums){
            if(v)
            {
                len++;
            }else{
                len = 0;
            }
            count = max(len,count);
        }
        return count;
    }
};