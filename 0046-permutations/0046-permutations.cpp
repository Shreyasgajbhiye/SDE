class Solution {
public:
    int fact(int n){
        if(n <=1) return 1;
        return n*fact(n-1);
    }

    vector<int> nextPerm(vector<int> &nums){
        int i=nums.size()-2;
        int j = nums.size()-1;

            while( i>= 0 && nums[i+1] <= nums[i]){
                i--;
            }
            if(i>=0){
                 while(nums[i] >=  nums[j]){
                    j--;
                }
                swap(nums[i], nums[j]);
            }

            reverse(nums.begin()+i+1, nums.end());
            return nums;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int f = fact(nums.size());
        vector<int> v;
            vector<vector<int>> x;
            v = nextPerm(nums);
            x.push_back(v);
        for(int i=0;i<f-1;i++){
            v = nextPerm(v);
            x.push_back(v);
        }
        return x;
    }
};