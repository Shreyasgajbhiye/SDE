class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int gola = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                gola = i-1;
                break;
            }
        }
        if(gola != -1){
            int swapi = gola;
            for(int i= nums.size()-1; i>gola;i--){
                if(nums[gola] < nums[i]){
                    swapi = i;
                    break;
                }
            }

            swap(nums[swapi], nums[gola]);
        }
        reverse(nums.begin() + gola+1, nums.end());
    }
};