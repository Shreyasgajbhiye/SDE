class Solution {
public:
    vector<int> getPer(vector<int> nums) {
        //5-7-25
        int idx1 = nums.size() - 2;
        int idx2 = nums.size() - 1;

        while (idx1 >= 0 && nums[idx1] >= nums[idx1 + 1]) {
            idx1--;
        }

        if (idx1 >= 0) {
            while (nums[idx2] <= nums[idx1]) {
                idx2--;
            }
            swap(nums[idx1], nums[idx2]);
        }

        reverse(nums.begin() + idx1 + 1, nums.end());
        return nums;
    }

    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {  
            v.push_back(i);
        }

        for (int i = 1; i < k; i++) {  
            v = getPer(v);
        }

        string s = "";
        for (auto num : v) {
            s += to_string(num);
        }

        return s; 
    }
};
