class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int j= i+1;
        int k = 1;
        while(i<nums.size() && j<nums.size() && i<=j){
            if(nums[j] == nums[i]){
                j++;
            }
            else{
                nums[i+1] = nums[j];
                i++;
                k++;
            }
        }
        return k;
    }
};