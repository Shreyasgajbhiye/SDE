class Solution {
public:
    vector<vector<int>> v;
    void subset(vector<int>& nums, int idx, vector<int>& temp, int sum, int k) {
        if(sum > k) return;
        if (idx == nums.size()) {
            if(sum == k) v.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        
        subset(nums, idx , temp, sum+nums[idx], k);
        temp.pop_back();
        subset(nums, idx + 1, temp, sum, k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> x;
        int sum = 0;
        subset(candidates, 0, x, sum, target);
        return v;
    }
};