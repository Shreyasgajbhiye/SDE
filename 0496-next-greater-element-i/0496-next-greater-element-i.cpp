class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> v(nums2.size());
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {

            while (!stk.empty() && nums2[i] > stk.top()) {
                mp[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        vector<int> v1;
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) {
                v1.push_back(mp[nums1[i]]);
            }
            else{
                v1.push_back(-1);
            }
        }
        return v1;
    }
};