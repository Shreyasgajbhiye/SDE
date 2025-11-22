class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> res1;
    void recursion(vector<int> &nums, int ind, vector<int> &v){
        if(ind == nums.size()){
            res.push_back(v);
            if(res1.find(v) == res1.end()){
                res1.insert(v);
            }
            return;
        }
        v.push_back(nums[ind]);
        recursion(nums, ind+1, v);
        v.pop_back();
        recursion(nums, ind+1, v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        recursion(nums, 0, v);
        
        vector<vector<int>> x;
        for(auto num : res1){
            x.push_back(num);
        }
        return x;
    }   
};