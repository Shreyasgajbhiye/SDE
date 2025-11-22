class Solution {
public:
    void merge(int low, int mid, int high, vector<int> &nums){
        int i = low;
        int j = mid+1;
        int k =0;
        vector<int> v(high-low+1);
        while(i<=mid && j<=high){
            if(nums[i] < nums[j]){
                v[k++] = nums[i++];
            }
            else{
                v[k++] = nums[j++];
            }
        }
        while(i <= mid){
            v[k++] = nums[i++]; 
        }

        while(j <= high){
            v[k++] = nums[j++]; 
        }
        for(int p =0;p<v.size();p++){
            nums[p + low] = v[p];
        }
        
    }
    void mergeSort(int low,int high, vector<int> &nums){
        while(low >= high) return;
            int mid =  low + (high - low) / 2;
            mergeSort(low, mid, nums);
            mergeSort(mid+1, high, nums);
            merge(low, mid, high, nums);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = high - low /2;
        mergeSort(low, high, nums);

       return nums;
    }
};