class Solution {
public:

    int bruteForce(vector<int> &nums){
        
        for(int i=0;i<nums.size();i++){
            int l=0;
            int r=0;
            for(int j=0;j<i;j++){
                l += nums[j];
            }

            for(int j=i+1;j<nums.size();j++){
                r += nums[j];
            }
            if( l == r) return i;
        }
        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        int x = bruteForce(nums);
        return x;
    }
};