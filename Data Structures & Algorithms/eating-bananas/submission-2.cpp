class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() -1;
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low < high){
            int mid = low + (high - low)/2;

            if(canEatWithIn(piles,mid,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    bool canEatWithIn(vector<int>& piles, int k , int h){
        long long total_hours = 0;
        for(auto pile : piles){
            total_hours += (pile+k-1LL)/k;

            if(total_hours > h){
                return false;
            }

        }
        return total_hours <= h;
    }
};
