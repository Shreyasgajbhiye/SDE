class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int prof = 0;
        int buy = nums[0];

        for(int i=1;i<nums.size();i++){
            if(buy > nums[i]){
                buy = nums[i];
            }

            prof = max(prof, nums[i]-buy);
        }
        return prof;
    }
};