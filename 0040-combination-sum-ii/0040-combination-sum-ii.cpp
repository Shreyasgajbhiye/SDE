class Solution {
public:
    vector<vector<int>> v;
    void subset(vector<int>& nums, int idx, vector<int>& temp, int sum, int k) {
        if(sum > k) return;
        if (idx == nums.size()) {
            if(sum == k){
                    v.push_back(temp);
            } 
            return;
        }

        temp.push_back(nums[idx]);
        
        subset(nums, idx +1, temp, sum+nums[idx], k);
        temp.pop_back();
        while(idx+1 < nums.size() && nums[idx] == nums[idx+1] ){
            idx++;
        }
        subset(nums, idx + 1, temp, sum, k);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> x;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        subset(candidates, 0, x, sum, target);
        return v;
    }
};