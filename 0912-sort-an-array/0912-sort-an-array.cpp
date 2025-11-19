class Solution {
public:
    int partition(vector<int> &nums, int l, int r){
        int pi = nums[l];
        int i=l;
        int j=r;

        while(i<j){
            while(nums[i] <= pi && i<=r-1){
                i++;
            }
            while(nums[j] > pi && j>=l+1){
                j--;
            }
            if(i<j) swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    void qs(vector<int> &nums, int l, int r){
        if(l<r){
            int part = partition(nums, l, r);
            qs(nums, l, part-1 );
            qs(nums, part+1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size()-1);
        return nums;
    }
};