class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(cnt <= 0){
                maj = nums[i];
                cnt++;
            }
            else{
                if(maj == nums[i]) cnt++;
                else cnt--;
            }
        }
        return maj;
    }
};